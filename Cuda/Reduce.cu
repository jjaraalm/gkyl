// Gkyl ------------------------------------------------------------------------
//
// Functions to compute reductions in GPU (Cuda).
//
//    _______     ___
// + 6 @ |||| # P ||| +
//------------------------------------------------------------------------------

#include <Reduce.h>

bool isPow2(unsigned int x) { return ((x & (x - 1)) == 0); }

unsigned int nextPow2(unsigned int x) {
  --x;
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  return ++x;
}

// Compute the number of threads and blocks to use for the given reduction
// kerne. We set threads/block to the minimum of maxThreads and n/2.
// We observe the maximum specified number of blocks, because
// each thread in the kernel can process a variable number of elements.
void reductionBlocksAndThreads(GkDeviceProp *prop, int numElements, int maxBlocks,
                               int maxThreads, int &blocks, int &threads) {

  threads = (numElements < maxThreads * 2) ? nextPow2((numElements + 1) / 2) : maxThreads;
  blocks  = (numElements + (threads * 2 - 1)) / (threads * 2);

  if ((float)threads * blocks >
      (float)(prop->maxGridSize)[0] * prop->maxThreadsPerBlock) {
    printf("n is too large, please choose a smaller number!\n");
  }

  if (blocks > (prop->maxGridSize)[0]) {
    printf("Grid size <%d> exceeds the device capability <%d>, set block size as %d (original %d)\n",
        blocks, (prop->maxGridSize)[0], threads * 2, threads);

    blocks  /= 2;
    threads *= 2;
  }

  blocks = MIN(maxBlocks, blocks);
}

// This algorithm reduces multiple elements per thread sequentially. This reduces
// the overall cost of the algorithm while keeping the work complexity O(n) and
// the step complexity O(log n). (Brent's Theorem optimization)
// Note, this kernel needs a minimum of 64*sizeof(T) bytes of shared memory.
// In other words if blockSize <= 32, allocate 64*sizeof(T) bytes.
// If blockSize > 32, allocate blockSize*sizeof(T) bytes.
template <unsigned int BLOCKSIZE, bool nIsPow2, unsigned int binOpType>
__global__ void d_reduce(double *dataIn, double *out, unsigned int nElements) {
  // Handle to thread block group.
  cg::thread_block cgThreadBlock = cg::this_thread_block();
  extern __shared__ double sdata[];  // Stores partial reductions.

  // Perform first level of reduction, reading from global memory, writing to shared memory.
  unsigned int tID       = threadIdx.x;
  unsigned int linearIdx = blockIdx.x * BLOCKSIZE * 2 + threadIdx.x;
  unsigned int gridSize  = BLOCKSIZE * 2 * gridDim.x;

  double myReduc = 0.0;
  if (binOpType==binOpMin) {
    myReduc = DBL_MAX;
  } else if (binOpType==binOpMax) {
    myReduc = -DBL_MAX;
  }

  // We reduce multiple elements per thread.  The number is determined by the
  // number of active thread blocks (via gridDim).  More blocks will result
  // in a larger gridSize and therefore fewer elements per thread
  while (linearIdx < nElements) {
    myReduc = binOp<binOpType>(myReduc, dataIn[linearIdx]);

    // Ensure we don't read out of bounds (optimized away for powerOf2 sized arrays)/
    if (nIsPow2 || linearIdx+BLOCKSIZE<nElements) myReduc = binOp<binOpType>(myReduc, dataIn[linearIdx+BLOCKSIZE]);

    linearIdx += gridSize;
  }

  // Each thread puts its local reduction into shared memory.
  sdata[tID] = myReduc;
  cg::sync(cgThreadBlock);

  // Do reduction in shared mem.
  if ((BLOCKSIZE >= 512) && (tID < 256)) {
    sdata[tID] = myReduc = binOp<binOpType>(myReduc, sdata[tID + 256]);
  }

  cg::sync(cgThreadBlock);

  if ((BLOCKSIZE >= 256) && (tID < 128)) {
    sdata[tID] = myReduc = binOp<binOpType>(myReduc, sdata[tID + 128]);
  }

  cg::sync(cgThreadBlock);

  if ((BLOCKSIZE >= 128) && (tID < 64)) {
    sdata[tID] = myReduc = binOp<binOpType>(myReduc, sdata[tID + 64]);
  }

  cg::sync(cgThreadBlock);

  cg::thread_block_tile<32> tile32 = cg::tiled_partition<32>(cgThreadBlock);

  if (cgThreadBlock.thread_rank() < 32) {
    // Fetch final intermediate reduction from 2nd warp.
    if (BLOCKSIZE >= 64) myReduc = binOp<binOpType>(myReduc, sdata[tID + 32]);
    // Reduce final warp using shuffle.
    for (int offset = tile32.size() / 2; offset > 0; offset /= 2) {
      double shflMax = tile32.shfl_down(myReduc, offset);
      myReduc = binOp<binOpType>(myReduc, shflMax);
    }
  }

  // Write result for this block to global mem.
  if (cgThreadBlock.thread_rank() == 0) { out[blockIdx.x] = myReduc; }
}

void reduceDeviceArray(int opIn, int numElements, int blocks, int threads, double *d_dataIn, double *d_dataOut) {
  // Launch the device kernel that reduces a device array 'd_dataIn'
  // containing 'numElements' elements.

  // When there is only one warp per block, we need to allocate two warps
  // worth of shared memory so that we don't index shared memory out of bounds
  int smemSize = (threads <= 32) ? 2 * threads * sizeof(double) : threads * sizeof(double);

  if (isPow2(numElements)) {
    switch (threads) {
      case 512:
        switch (opIn) {
          case 1:
            d_reduce<512,true,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<512,true,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<512,true,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
      case 256:
        switch (opIn) {
          case 1:
            d_reduce<256,true,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<256,true,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<256,true,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
      case 128:
        switch (opIn) {
          case 1:
            d_reduce<128,true,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<128,true,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<128,true,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
      case 64:
        switch (opIn) {
          case 1:
            d_reduce<64,true,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<64,true,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<64,true,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
      case 32:
        switch (opIn) {
          case 1:
            d_reduce<32,true,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<32,true,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<32,true,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
      case 16:
        switch (opIn) {
          case 1:
            d_reduce<16,true,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<16,true,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<16,true,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
      case 8:
        switch (opIn) {
          case 1:
            d_reduce<8,true,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<8,true,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<8,true,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
      case 4:
        switch (opIn) {
          case 1:
            d_reduce<4,true,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<4,true,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<4,true,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
      case 2:
        switch (opIn) {
          case 1:
            d_reduce<2,true,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<2,true,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<2,true,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
      case 1:
        switch (opIn) {
          case 1:
            d_reduce<1,true,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<1,true,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<1,true,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
    }
  } else {
    switch (threads) {
      case 512:
        switch (opIn) {
          case 1:
            d_reduce<512,false,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<512,false,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<512,false,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
      case 256:
        switch (opIn) {
          case 1:
            d_reduce<256,false,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<256,false,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<256,false,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
      case 128:
        switch (opIn) {
          case 1:
            d_reduce<128,false,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<128,false,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<128,false,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
      case 64:
        switch (opIn) {
          case 1:
            d_reduce<64,false,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<64,false,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<64,false,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
      case 32:
        switch (opIn) {
          case 1:
            d_reduce<32,false,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<32,false,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<32,false,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
      case 16:
        switch (opIn) {
          case 1:
            d_reduce<16,false,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<16,false,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<16,false,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
      case 8:
        switch (opIn) {
          case 1:
            d_reduce<8,false,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<8,false,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<8,false,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
      case 4:
        switch (opIn) {
          case 1:
            d_reduce<4,false,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<4,false,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<4,false,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
      case 2:
        switch (opIn) {
          case 1:
            d_reduce<2,false,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<2,false,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<2,false,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
      case 1:
        switch (opIn) {
          case 1:
            d_reduce<1,false,binOpMin><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 2:
            d_reduce<1,false,binOpMax><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
          case 3:
            d_reduce<1,false,binOpSum><<<blocks,threads,smemSize>>>(d_dataIn, d_dataOut, numElements);
            break;
        }
        break;
    }
  }
}

