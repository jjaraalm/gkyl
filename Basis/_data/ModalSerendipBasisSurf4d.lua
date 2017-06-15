local _M = {} 
-- polyOrder 1 
_M[1] = {} 
--    dir 1 
_M[1][1] = {} 
_M[1][1].upper = function (volIn, surfOut) 
   surfOut[1] = 1.224744871391589*volIn[2]+0.7071067811865475*volIn[1] 
   surfOut[2] = 1.224744871391589*volIn[7]+0.7071067811865475*volIn[3] 
   surfOut[3] = 1.224744871391589*volIn[8]+0.7071067811865475*volIn[4] 
   surfOut[4] = 1.224744871391589*volIn[10]+0.7071067811865475*volIn[5] 
   surfOut[5] = 1.224744871391589*volIn[13]+0.7071067811865475*volIn[6] 
   surfOut[6] = 1.224744871391589*volIn[17]+0.7071067811865475*volIn[9] 
   surfOut[7] = 1.224744871391589*volIn[18]+0.7071067811865475*volIn[11] 
   surfOut[8] = 1.224744871391589*volIn[19]+0.7071067811865475*volIn[12] 
   surfOut[9] = 1.224744871391589*volIn[21]+0.7071067811865475*volIn[14] 
   surfOut[10] = 1.224744871391589*volIn[22]+0.7071067811865475*volIn[15] 
   surfOut[11] = 1.224744871391589*volIn[24]+0.7071067811865475*volIn[16] 
   surfOut[12] = 1.224744871391589*volIn[27]+0.7071067811865475*volIn[20] 
   surfOut[13] = 1.224744871391589*volIn[28]+0.7071067811865475*volIn[23] 
   surfOut[14] = 1.224744871391589*volIn[29]+0.7071067811865475*volIn[25] 
   surfOut[15] = 1.224744871391589*volIn[30]+0.7071067811865475*volIn[26] 
   surfOut[16] = 1.224744871391589*volIn[32]+0.7071067811865475*volIn[31] 
end 
_M[1][1].lower = function (volIn, surfOut) 
   surfOut[1] = 0.7071067811865475*volIn[1]-1.224744871391589*volIn[2] 
   surfOut[2] = 0.7071067811865475*volIn[3]-1.224744871391589*volIn[7] 
   surfOut[3] = 0.7071067811865475*volIn[4]-1.224744871391589*volIn[8] 
   surfOut[4] = 0.7071067811865475*volIn[5]-1.224744871391589*volIn[10] 
   surfOut[5] = 0.7071067811865475*volIn[6]-1.224744871391589*volIn[13] 
   surfOut[6] = 0.7071067811865475*volIn[9]-1.224744871391589*volIn[17] 
   surfOut[7] = 0.7071067811865475*volIn[11]-1.224744871391589*volIn[18] 
   surfOut[8] = 0.7071067811865475*volIn[12]-1.224744871391589*volIn[19] 
   surfOut[9] = 0.7071067811865475*volIn[14]-1.224744871391589*volIn[21] 
   surfOut[10] = 0.7071067811865475*volIn[15]-1.224744871391589*volIn[22] 
   surfOut[11] = 0.7071067811865475*volIn[16]-1.224744871391589*volIn[24] 
   surfOut[12] = 0.7071067811865475*volIn[20]-1.224744871391589*volIn[27] 
   surfOut[13] = 0.7071067811865475*volIn[23]-1.224744871391589*volIn[28] 
   surfOut[14] = 0.7071067811865475*volIn[25]-1.224744871391589*volIn[29] 
   surfOut[15] = 0.7071067811865475*volIn[26]-1.224744871391589*volIn[30] 
   surfOut[16] = 0.7071067811865475*volIn[31]-1.224744871391589*volIn[32] 
end 

--    dir 2 
_M[1][2] = {} 
_M[1][2].upper = function (volIn, surfOut) 
   surfOut[1] = 1.224744871391589*volIn[3]+0.7071067811865475*volIn[1] 
   surfOut[2] = 1.224744871391589*volIn[7]+0.7071067811865475*volIn[2] 
   surfOut[3] = 1.224744871391589*volIn[9]+0.7071067811865475*volIn[4] 
   surfOut[4] = 1.224744871391589*volIn[11]+0.7071067811865475*volIn[5] 
   surfOut[5] = 1.224744871391589*volIn[14]+0.7071067811865475*volIn[6] 
   surfOut[6] = 1.224744871391589*volIn[17]+0.7071067811865475*volIn[8] 
   surfOut[7] = 1.224744871391589*volIn[18]+0.7071067811865475*volIn[10] 
   surfOut[8] = 1.224744871391589*volIn[20]+0.7071067811865475*volIn[12] 
   surfOut[9] = 1.224744871391589*volIn[21]+0.7071067811865475*volIn[13] 
   surfOut[10] = 1.224744871391589*volIn[23]+0.7071067811865475*volIn[15] 
   surfOut[11] = 1.224744871391589*volIn[25]+0.7071067811865475*volIn[16] 
   surfOut[12] = 1.224744871391589*volIn[27]+0.7071067811865475*volIn[19] 
   surfOut[13] = 1.224744871391589*volIn[28]+0.7071067811865475*volIn[22] 
   surfOut[14] = 1.224744871391589*volIn[29]+0.7071067811865475*volIn[24] 
   surfOut[15] = 1.224744871391589*volIn[31]+0.7071067811865475*volIn[26] 
   surfOut[16] = 1.224744871391589*volIn[32]+0.7071067811865475*volIn[30] 
end 
_M[1][2].lower = function (volIn, surfOut) 
   surfOut[1] = 0.7071067811865475*volIn[1]-1.224744871391589*volIn[3] 
   surfOut[2] = 0.7071067811865475*volIn[2]-1.224744871391589*volIn[7] 
   surfOut[3] = 0.7071067811865475*volIn[4]-1.224744871391589*volIn[9] 
   surfOut[4] = 0.7071067811865475*volIn[5]-1.224744871391589*volIn[11] 
   surfOut[5] = 0.7071067811865475*volIn[6]-1.224744871391589*volIn[14] 
   surfOut[6] = 0.7071067811865475*volIn[8]-1.224744871391589*volIn[17] 
   surfOut[7] = 0.7071067811865475*volIn[10]-1.224744871391589*volIn[18] 
   surfOut[8] = 0.7071067811865475*volIn[12]-1.224744871391589*volIn[20] 
   surfOut[9] = 0.7071067811865475*volIn[13]-1.224744871391589*volIn[21] 
   surfOut[10] = 0.7071067811865475*volIn[15]-1.224744871391589*volIn[23] 
   surfOut[11] = 0.7071067811865475*volIn[16]-1.224744871391589*volIn[25] 
   surfOut[12] = 0.7071067811865475*volIn[19]-1.224744871391589*volIn[27] 
   surfOut[13] = 0.7071067811865475*volIn[22]-1.224744871391589*volIn[28] 
   surfOut[14] = 0.7071067811865475*volIn[24]-1.224744871391589*volIn[29] 
   surfOut[15] = 0.7071067811865475*volIn[26]-1.224744871391589*volIn[31] 
   surfOut[16] = 0.7071067811865475*volIn[30]-1.224744871391589*volIn[32] 
end 

--    dir 3 
_M[1][3] = {} 
_M[1][3].upper = function (volIn, surfOut) 
   surfOut[1] = 1.224744871391589*volIn[4]+0.7071067811865475*volIn[1] 
   surfOut[2] = 1.224744871391589*volIn[8]+0.7071067811865475*volIn[2] 
   surfOut[3] = 1.224744871391589*volIn[9]+0.7071067811865475*volIn[3] 
   surfOut[4] = 1.224744871391589*volIn[12]+0.7071067811865475*volIn[5] 
   surfOut[5] = 1.224744871391589*volIn[15]+0.7071067811865475*volIn[6] 
   surfOut[6] = 1.224744871391589*volIn[17]+0.7071067811865475*volIn[7] 
   surfOut[7] = 1.224744871391589*volIn[19]+0.7071067811865475*volIn[10] 
   surfOut[8] = 1.224744871391589*volIn[20]+0.7071067811865475*volIn[11] 
   surfOut[9] = 1.224744871391589*volIn[22]+0.7071067811865475*volIn[13] 
   surfOut[10] = 1.224744871391589*volIn[23]+0.7071067811865475*volIn[14] 
   surfOut[11] = 1.224744871391589*volIn[26]+0.7071067811865475*volIn[16] 
   surfOut[12] = 1.224744871391589*volIn[27]+0.7071067811865475*volIn[18] 
   surfOut[13] = 1.224744871391589*volIn[28]+0.7071067811865475*volIn[21] 
   surfOut[14] = 1.224744871391589*volIn[30]+0.7071067811865475*volIn[24] 
   surfOut[15] = 1.224744871391589*volIn[31]+0.7071067811865475*volIn[25] 
   surfOut[16] = 1.224744871391589*volIn[32]+0.7071067811865475*volIn[29] 
end 
_M[1][3].lower = function (volIn, surfOut) 
   surfOut[1] = 0.7071067811865475*volIn[1]-1.224744871391589*volIn[4] 
   surfOut[2] = 0.7071067811865475*volIn[2]-1.224744871391589*volIn[8] 
   surfOut[3] = 0.7071067811865475*volIn[3]-1.224744871391589*volIn[9] 
   surfOut[4] = 0.7071067811865475*volIn[5]-1.224744871391589*volIn[12] 
   surfOut[5] = 0.7071067811865475*volIn[6]-1.224744871391589*volIn[15] 
   surfOut[6] = 0.7071067811865475*volIn[7]-1.224744871391589*volIn[17] 
   surfOut[7] = 0.7071067811865475*volIn[10]-1.224744871391589*volIn[19] 
   surfOut[8] = 0.7071067811865475*volIn[11]-1.224744871391589*volIn[20] 
   surfOut[9] = 0.7071067811865475*volIn[13]-1.224744871391589*volIn[22] 
   surfOut[10] = 0.7071067811865475*volIn[14]-1.224744871391589*volIn[23] 
   surfOut[11] = 0.7071067811865475*volIn[16]-1.224744871391589*volIn[26] 
   surfOut[12] = 0.7071067811865475*volIn[18]-1.224744871391589*volIn[27] 
   surfOut[13] = 0.7071067811865475*volIn[21]-1.224744871391589*volIn[28] 
   surfOut[14] = 0.7071067811865475*volIn[24]-1.224744871391589*volIn[30] 
   surfOut[15] = 0.7071067811865475*volIn[25]-1.224744871391589*volIn[31] 
   surfOut[16] = 0.7071067811865475*volIn[29]-1.224744871391589*volIn[32] 
end 

--    dir 4 
_M[1][4] = {} 
_M[1][4].upper = function (volIn, surfOut) 
   surfOut[1] = 1.224744871391589*volIn[5]+0.7071067811865475*volIn[1] 
   surfOut[2] = 1.224744871391589*volIn[10]+0.7071067811865475*volIn[2] 
   surfOut[3] = 1.224744871391589*volIn[11]+0.7071067811865475*volIn[3] 
   surfOut[4] = 1.224744871391589*volIn[12]+0.7071067811865475*volIn[4] 
   surfOut[5] = 1.224744871391589*volIn[16]+0.7071067811865475*volIn[6] 
   surfOut[6] = 1.224744871391589*volIn[18]+0.7071067811865475*volIn[7] 
   surfOut[7] = 1.224744871391589*volIn[19]+0.7071067811865475*volIn[8] 
   surfOut[8] = 1.224744871391589*volIn[20]+0.7071067811865475*volIn[9] 
   surfOut[9] = 1.224744871391589*volIn[24]+0.7071067811865475*volIn[13] 
   surfOut[10] = 1.224744871391589*volIn[25]+0.7071067811865475*volIn[14] 
   surfOut[11] = 1.224744871391589*volIn[26]+0.7071067811865475*volIn[15] 
   surfOut[12] = 1.224744871391589*volIn[27]+0.7071067811865475*volIn[17] 
   surfOut[13] = 1.224744871391589*volIn[29]+0.7071067811865475*volIn[21] 
   surfOut[14] = 1.224744871391589*volIn[30]+0.7071067811865475*volIn[22] 
   surfOut[15] = 1.224744871391589*volIn[31]+0.7071067811865475*volIn[23] 
   surfOut[16] = 1.224744871391589*volIn[32]+0.7071067811865475*volIn[28] 
end 
_M[1][4].lower = function (volIn, surfOut) 
   surfOut[1] = 0.7071067811865475*volIn[1]-1.224744871391589*volIn[5] 
   surfOut[2] = 0.7071067811865475*volIn[2]-1.224744871391589*volIn[10] 
   surfOut[3] = 0.7071067811865475*volIn[3]-1.224744871391589*volIn[11] 
   surfOut[4] = 0.7071067811865475*volIn[4]-1.224744871391589*volIn[12] 
   surfOut[5] = 0.7071067811865475*volIn[6]-1.224744871391589*volIn[16] 
   surfOut[6] = 0.7071067811865475*volIn[7]-1.224744871391589*volIn[18] 
   surfOut[7] = 0.7071067811865475*volIn[8]-1.224744871391589*volIn[19] 
   surfOut[8] = 0.7071067811865475*volIn[9]-1.224744871391589*volIn[20] 
   surfOut[9] = 0.7071067811865475*volIn[13]-1.224744871391589*volIn[24] 
   surfOut[10] = 0.7071067811865475*volIn[14]-1.224744871391589*volIn[25] 
   surfOut[11] = 0.7071067811865475*volIn[15]-1.224744871391589*volIn[26] 
   surfOut[12] = 0.7071067811865475*volIn[17]-1.224744871391589*volIn[27] 
   surfOut[13] = 0.7071067811865475*volIn[21]-1.224744871391589*volIn[29] 
   surfOut[14] = 0.7071067811865475*volIn[22]-1.224744871391589*volIn[30] 
   surfOut[15] = 0.7071067811865475*volIn[23]-1.224744871391589*volIn[31] 
   surfOut[16] = 0.7071067811865475*volIn[28]-1.224744871391589*volIn[32] 
end 

--    dir 5 
_M[1][5] = {} 
_M[1][5].upper = function (volIn, surfOut) 
   surfOut[1] = 1.224744871391589*volIn[6]+0.7071067811865475*volIn[1] 
   surfOut[2] = 1.224744871391589*volIn[13]+0.7071067811865475*volIn[2] 
   surfOut[3] = 1.224744871391589*volIn[14]+0.7071067811865475*volIn[3] 
   surfOut[4] = 1.224744871391589*volIn[15]+0.7071067811865475*volIn[4] 
   surfOut[5] = 1.224744871391589*volIn[16]+0.7071067811865475*volIn[5] 
   surfOut[6] = 1.224744871391589*volIn[21]+0.7071067811865475*volIn[7] 
   surfOut[7] = 1.224744871391589*volIn[22]+0.7071067811865475*volIn[8] 
   surfOut[8] = 1.224744871391589*volIn[23]+0.7071067811865475*volIn[9] 
   surfOut[9] = 1.224744871391589*volIn[24]+0.7071067811865475*volIn[10] 
   surfOut[10] = 1.224744871391589*volIn[25]+0.7071067811865475*volIn[11] 
   surfOut[11] = 1.224744871391589*volIn[26]+0.7071067811865475*volIn[12] 
   surfOut[12] = 1.224744871391589*volIn[28]+0.7071067811865475*volIn[17] 
   surfOut[13] = 1.224744871391589*volIn[29]+0.7071067811865475*volIn[18] 
   surfOut[14] = 1.224744871391589*volIn[30]+0.7071067811865475*volIn[19] 
   surfOut[15] = 1.224744871391589*volIn[31]+0.7071067811865475*volIn[20] 
   surfOut[16] = 1.224744871391589*volIn[32]+0.7071067811865475*volIn[27] 
end 
_M[1][5].lower = function (volIn, surfOut) 
   surfOut[1] = 0.7071067811865475*volIn[1]-1.224744871391589*volIn[6] 
   surfOut[2] = 0.7071067811865475*volIn[2]-1.224744871391589*volIn[13] 
   surfOut[3] = 0.7071067811865475*volIn[3]-1.224744871391589*volIn[14] 
   surfOut[4] = 0.7071067811865475*volIn[4]-1.224744871391589*volIn[15] 
   surfOut[5] = 0.7071067811865475*volIn[5]-1.224744871391589*volIn[16] 
   surfOut[6] = 0.7071067811865475*volIn[7]-1.224744871391589*volIn[21] 
   surfOut[7] = 0.7071067811865475*volIn[8]-1.224744871391589*volIn[22] 
   surfOut[8] = 0.7071067811865475*volIn[9]-1.224744871391589*volIn[23] 
   surfOut[9] = 0.7071067811865475*volIn[10]-1.224744871391589*volIn[24] 
   surfOut[10] = 0.7071067811865475*volIn[11]-1.224744871391589*volIn[25] 
   surfOut[11] = 0.7071067811865475*volIn[12]-1.224744871391589*volIn[26] 
   surfOut[12] = 0.7071067811865475*volIn[17]-1.224744871391589*volIn[28] 
   surfOut[13] = 0.7071067811865475*volIn[18]-1.224744871391589*volIn[29] 
   surfOut[14] = 0.7071067811865475*volIn[19]-1.224744871391589*volIn[30] 
   surfOut[15] = 0.7071067811865475*volIn[20]-1.224744871391589*volIn[31] 
   surfOut[16] = 0.7071067811865475*volIn[27]-1.224744871391589*volIn[32] 
end 


-- polyOrder 2 
_M[2] = {} 
--    dir 1 
_M[2][1] = {} 
_M[2][1].upper = function (volIn, surfOut) 
   surfOut[1] = 1.58113883008419*volIn[17]+1.224744871391589*volIn[2]+0.7071067811865475*volIn[1] 
   surfOut[2] = 1.58113883008419*volIn[32]+1.224744871391589*volIn[7]+0.7071067811865475*volIn[3] 
   surfOut[3] = 1.58113883008419*volIn[34]+1.224744871391589*volIn[8]+0.7071067811865475*volIn[4] 
   surfOut[4] = 1.58113883008419*volIn[38]+1.224744871391589*volIn[10]+0.7071067811865475*volIn[5] 
   surfOut[5] = 1.58113883008419*volIn[44]+1.224744871391589*volIn[13]+0.7071067811865475*volIn[6] 
   surfOut[6] = 1.58113883008419*volIn[57]+1.224744871391589*volIn[22]+0.7071067811865475*volIn[9] 
   surfOut[7] = 1.58113883008419*volIn[60]+1.224744871391589*volIn[23]+0.7071067811865475*volIn[11] 
   surfOut[8] = 1.58113883008419*volIn[62]+1.224744871391589*volIn[24]+0.7071067811865475*volIn[12] 
   surfOut[9] = 1.58113883008419*volIn[69]+1.224744871391589*volIn[26]+0.7071067811865475*volIn[14] 
   surfOut[10] = 1.58113883008419*volIn[71]+1.224744871391589*volIn[27]+0.7071067811865475*volIn[15] 
   surfOut[11] = 1.58113883008419*volIn[75]+1.224744871391589*volIn[29]+0.7071067811865475*volIn[16] 
   surfOut[12] = 1.224744871391589*volIn[33]+0.7071067811865475*volIn[18] 
   surfOut[13] = 1.224744871391589*volIn[36]+0.7071067811865475*volIn[19] 
   surfOut[14] = 1.224744871391589*volIn[41]+0.7071067811865475*volIn[20] 
   surfOut[15] = 1.224744871391589*volIn[48]+0.7071067811865475*volIn[21] 
   surfOut[16] = 1.58113883008419*volIn[88]+1.224744871391589*volIn[52]+0.7071067811865475*volIn[25] 
   surfOut[17] = 1.58113883008419*volIn[92]+1.224744871391589*volIn[53]+0.7071067811865475*volIn[28] 
   surfOut[18] = 1.58113883008419*volIn[95]+1.224744871391589*volIn[54]+0.7071067811865475*volIn[30] 
   surfOut[19] = 1.58113883008419*volIn[97]+1.224744871391589*volIn[55]+0.7071067811865475*volIn[31] 
   surfOut[20] = 1.224744871391589*volIn[58]+0.7071067811865475*volIn[35] 
   surfOut[21] = 1.224744871391589*volIn[59]+0.7071067811865475*volIn[37] 
   surfOut[22] = 1.224744871391589*volIn[61]+0.7071067811865475*volIn[39] 
   surfOut[23] = 1.224744871391589*volIn[64]+0.7071067811865475*volIn[40] 
   surfOut[24] = 1.224744871391589*volIn[66]+0.7071067811865475*volIn[42] 
   surfOut[25] = 1.224744871391589*volIn[67]+0.7071067811865475*volIn[43] 
   surfOut[26] = 1.224744871391589*volIn[70]+0.7071067811865475*volIn[45] 
   surfOut[27] = 1.224744871391589*volIn[73]+0.7071067811865475*volIn[46] 
   surfOut[28] = 1.224744871391589*volIn[78]+0.7071067811865475*volIn[47] 
   surfOut[29] = 1.224744871391589*volIn[81]+0.7071067811865475*volIn[49] 
   surfOut[30] = 1.224744871391589*volIn[82]+0.7071067811865475*volIn[50] 
   surfOut[31] = 1.224744871391589*volIn[84]+0.7071067811865475*volIn[51] 
   surfOut[32] = 1.58113883008419*volIn[108]+1.224744871391589*volIn[87]+0.7071067811865475*volIn[56] 
   surfOut[33] = 1.224744871391589*volIn[89]+0.7071067811865475*volIn[63] 
   surfOut[34] = 1.224744871391589*volIn[90]+0.7071067811865475*volIn[65] 
   surfOut[35] = 1.224744871391589*volIn[91]+0.7071067811865475*volIn[68] 
   surfOut[36] = 1.224744871391589*volIn[93]+0.7071067811865475*volIn[72] 
   surfOut[37] = 1.224744871391589*volIn[94]+0.7071067811865475*volIn[74] 
   surfOut[38] = 1.224744871391589*volIn[96]+0.7071067811865475*volIn[76] 
   surfOut[39] = 1.224744871391589*volIn[99]+0.7071067811865475*volIn[77] 
   surfOut[40] = 1.224744871391589*volIn[101]+0.7071067811865475*volIn[79] 
   surfOut[41] = 1.224744871391589*volIn[102]+0.7071067811865475*volIn[80] 
   surfOut[42] = 1.224744871391589*volIn[104]+0.7071067811865475*volIn[83] 
   surfOut[43] = 1.224744871391589*volIn[105]+0.7071067811865475*volIn[85] 
   surfOut[44] = 1.224744871391589*volIn[106]+0.7071067811865475*volIn[86] 
   surfOut[45] = 1.224744871391589*volIn[109]+0.7071067811865475*volIn[98] 
   surfOut[46] = 1.224744871391589*volIn[110]+0.7071067811865475*volIn[100] 
   surfOut[47] = 1.224744871391589*volIn[111]+0.7071067811865475*volIn[103] 
   surfOut[48] = 1.224744871391589*volIn[112]+0.7071067811865475*volIn[107] 
end 
_M[2][1].lower = function (volIn, surfOut) 
   surfOut[1] = 1.58113883008419*volIn[17]-1.224744871391589*volIn[2]+0.7071067811865475*volIn[1] 
   surfOut[2] = 1.58113883008419*volIn[32]-1.224744871391589*volIn[7]+0.7071067811865475*volIn[3] 
   surfOut[3] = 1.58113883008419*volIn[34]-1.224744871391589*volIn[8]+0.7071067811865475*volIn[4] 
   surfOut[4] = 1.58113883008419*volIn[38]-1.224744871391589*volIn[10]+0.7071067811865475*volIn[5] 
   surfOut[5] = 1.58113883008419*volIn[44]-1.224744871391589*volIn[13]+0.7071067811865475*volIn[6] 
   surfOut[6] = 1.58113883008419*volIn[57]-1.224744871391589*volIn[22]+0.7071067811865475*volIn[9] 
   surfOut[7] = 1.58113883008419*volIn[60]-1.224744871391589*volIn[23]+0.7071067811865475*volIn[11] 
   surfOut[8] = 1.58113883008419*volIn[62]-1.224744871391589*volIn[24]+0.7071067811865475*volIn[12] 
   surfOut[9] = 1.58113883008419*volIn[69]-1.224744871391589*volIn[26]+0.7071067811865475*volIn[14] 
   surfOut[10] = 1.58113883008419*volIn[71]-1.224744871391589*volIn[27]+0.7071067811865475*volIn[15] 
   surfOut[11] = 1.58113883008419*volIn[75]-1.224744871391589*volIn[29]+0.7071067811865475*volIn[16] 
   surfOut[12] = 0.7071067811865475*volIn[18]-1.224744871391589*volIn[33] 
   surfOut[13] = 0.7071067811865475*volIn[19]-1.224744871391589*volIn[36] 
   surfOut[14] = 0.7071067811865475*volIn[20]-1.224744871391589*volIn[41] 
   surfOut[15] = 0.7071067811865475*volIn[21]-1.224744871391589*volIn[48] 
   surfOut[16] = 1.58113883008419*volIn[88]-1.224744871391589*volIn[52]+0.7071067811865475*volIn[25] 
   surfOut[17] = 1.58113883008419*volIn[92]-1.224744871391589*volIn[53]+0.7071067811865475*volIn[28] 
   surfOut[18] = 1.58113883008419*volIn[95]-1.224744871391589*volIn[54]+0.7071067811865475*volIn[30] 
   surfOut[19] = 1.58113883008419*volIn[97]-1.224744871391589*volIn[55]+0.7071067811865475*volIn[31] 
   surfOut[20] = 0.7071067811865475*volIn[35]-1.224744871391589*volIn[58] 
   surfOut[21] = 0.7071067811865475*volIn[37]-1.224744871391589*volIn[59] 
   surfOut[22] = 0.7071067811865475*volIn[39]-1.224744871391589*volIn[61] 
   surfOut[23] = 0.7071067811865475*volIn[40]-1.224744871391589*volIn[64] 
   surfOut[24] = 0.7071067811865475*volIn[42]-1.224744871391589*volIn[66] 
   surfOut[25] = 0.7071067811865475*volIn[43]-1.224744871391589*volIn[67] 
   surfOut[26] = 0.7071067811865475*volIn[45]-1.224744871391589*volIn[70] 
   surfOut[27] = 0.7071067811865475*volIn[46]-1.224744871391589*volIn[73] 
   surfOut[28] = 0.7071067811865475*volIn[47]-1.224744871391589*volIn[78] 
   surfOut[29] = 0.7071067811865475*volIn[49]-1.224744871391589*volIn[81] 
   surfOut[30] = 0.7071067811865475*volIn[50]-1.224744871391589*volIn[82] 
   surfOut[31] = 0.7071067811865475*volIn[51]-1.224744871391589*volIn[84] 
   surfOut[32] = 1.58113883008419*volIn[108]-1.224744871391589*volIn[87]+0.7071067811865475*volIn[56] 
   surfOut[33] = 0.7071067811865475*volIn[63]-1.224744871391589*volIn[89] 
   surfOut[34] = 0.7071067811865475*volIn[65]-1.224744871391589*volIn[90] 
   surfOut[35] = 0.7071067811865475*volIn[68]-1.224744871391589*volIn[91] 
   surfOut[36] = 0.7071067811865475*volIn[72]-1.224744871391589*volIn[93] 
   surfOut[37] = 0.7071067811865475*volIn[74]-1.224744871391589*volIn[94] 
   surfOut[38] = 0.7071067811865475*volIn[76]-1.224744871391589*volIn[96] 
   surfOut[39] = 0.7071067811865475*volIn[77]-1.224744871391589*volIn[99] 
   surfOut[40] = 0.7071067811865475*volIn[79]-1.224744871391589*volIn[101] 
   surfOut[41] = 0.7071067811865475*volIn[80]-1.224744871391589*volIn[102] 
   surfOut[42] = 0.7071067811865475*volIn[83]-1.224744871391589*volIn[104] 
   surfOut[43] = 0.7071067811865475*volIn[85]-1.224744871391589*volIn[105] 
   surfOut[44] = 0.7071067811865475*volIn[86]-1.224744871391589*volIn[106] 
   surfOut[45] = 0.7071067811865475*volIn[98]-1.224744871391589*volIn[109] 
   surfOut[46] = 0.7071067811865475*volIn[100]-1.224744871391589*volIn[110] 
   surfOut[47] = 0.7071067811865475*volIn[103]-1.224744871391589*volIn[111] 
   surfOut[48] = 0.7071067811865475*volIn[107]-1.224744871391589*volIn[112] 
end 

--    dir 2 
_M[2][2] = {} 
_M[2][2].upper = function (volIn, surfOut) 
   surfOut[1] = 1.58113883008419*volIn[18]+1.224744871391589*volIn[3]+0.7071067811865475*volIn[1] 
   surfOut[2] = 1.58113883008419*volIn[33]+1.224744871391589*volIn[7]+0.7071067811865475*volIn[2] 
   surfOut[3] = 1.58113883008419*volIn[35]+1.224744871391589*volIn[9]+0.7071067811865475*volIn[4] 
   surfOut[4] = 1.58113883008419*volIn[39]+1.224744871391589*volIn[11]+0.7071067811865475*volIn[5] 
   surfOut[5] = 1.58113883008419*volIn[45]+1.224744871391589*volIn[14]+0.7071067811865475*volIn[6] 
   surfOut[6] = 1.58113883008419*volIn[58]+1.224744871391589*volIn[22]+0.7071067811865475*volIn[8] 
   surfOut[7] = 1.58113883008419*volIn[61]+1.224744871391589*volIn[23]+0.7071067811865475*volIn[10] 
   surfOut[8] = 1.58113883008419*volIn[63]+1.224744871391589*volIn[25]+0.7071067811865475*volIn[12] 
   surfOut[9] = 1.58113883008419*volIn[70]+1.224744871391589*volIn[26]+0.7071067811865475*volIn[13] 
   surfOut[10] = 1.58113883008419*volIn[72]+1.224744871391589*volIn[28]+0.7071067811865475*volIn[15] 
   surfOut[11] = 1.58113883008419*volIn[76]+1.224744871391589*volIn[30]+0.7071067811865475*volIn[16] 
   surfOut[12] = 1.224744871391589*volIn[32]+0.7071067811865475*volIn[17] 
   surfOut[13] = 1.224744871391589*volIn[37]+0.7071067811865475*volIn[19] 
   surfOut[14] = 1.224744871391589*volIn[42]+0.7071067811865475*volIn[20] 
   surfOut[15] = 1.224744871391589*volIn[49]+0.7071067811865475*volIn[21] 
   surfOut[16] = 1.58113883008419*volIn[89]+1.224744871391589*volIn[52]+0.7071067811865475*volIn[24] 
   surfOut[17] = 1.58113883008419*volIn[93]+1.224744871391589*volIn[53]+0.7071067811865475*volIn[27] 
   surfOut[18] = 1.58113883008419*volIn[96]+1.224744871391589*volIn[54]+0.7071067811865475*volIn[29] 
   surfOut[19] = 1.58113883008419*volIn[98]+1.224744871391589*volIn[56]+0.7071067811865475*volIn[31] 
   surfOut[20] = 1.224744871391589*volIn[57]+0.7071067811865475*volIn[34] 
   surfOut[21] = 1.224744871391589*volIn[59]+0.7071067811865475*volIn[36] 
   surfOut[22] = 1.224744871391589*volIn[60]+0.7071067811865475*volIn[38] 
   surfOut[23] = 1.224744871391589*volIn[65]+0.7071067811865475*volIn[40] 
   surfOut[24] = 1.224744871391589*volIn[66]+0.7071067811865475*volIn[41] 
   surfOut[25] = 1.224744871391589*volIn[68]+0.7071067811865475*volIn[43] 
   surfOut[26] = 1.224744871391589*volIn[69]+0.7071067811865475*volIn[44] 
   surfOut[27] = 1.224744871391589*volIn[74]+0.7071067811865475*volIn[46] 
   surfOut[28] = 1.224744871391589*volIn[79]+0.7071067811865475*volIn[47] 
   surfOut[29] = 1.224744871391589*volIn[81]+0.7071067811865475*volIn[48] 
   surfOut[30] = 1.224744871391589*volIn[83]+0.7071067811865475*volIn[50] 
   surfOut[31] = 1.224744871391589*volIn[85]+0.7071067811865475*volIn[51] 
   surfOut[32] = 1.58113883008419*volIn[109]+1.224744871391589*volIn[87]+0.7071067811865475*volIn[55] 
   surfOut[33] = 1.224744871391589*volIn[88]+0.7071067811865475*volIn[62] 
   surfOut[34] = 1.224744871391589*volIn[90]+0.7071067811865475*volIn[64] 
   surfOut[35] = 1.224744871391589*volIn[91]+0.7071067811865475*volIn[67] 
   surfOut[36] = 1.224744871391589*volIn[92]+0.7071067811865475*volIn[71] 
   surfOut[37] = 1.224744871391589*volIn[94]+0.7071067811865475*volIn[73] 
   surfOut[38] = 1.224744871391589*volIn[95]+0.7071067811865475*volIn[75] 
   surfOut[39] = 1.224744871391589*volIn[100]+0.7071067811865475*volIn[77] 
   surfOut[40] = 1.224744871391589*volIn[101]+0.7071067811865475*volIn[78] 
   surfOut[41] = 1.224744871391589*volIn[103]+0.7071067811865475*volIn[80] 
   surfOut[42] = 1.224744871391589*volIn[104]+0.7071067811865475*volIn[82] 
   surfOut[43] = 1.224744871391589*volIn[105]+0.7071067811865475*volIn[84] 
   surfOut[44] = 1.224744871391589*volIn[107]+0.7071067811865475*volIn[86] 
   surfOut[45] = 1.224744871391589*volIn[108]+0.7071067811865475*volIn[97] 
   surfOut[46] = 1.224744871391589*volIn[110]+0.7071067811865475*volIn[99] 
   surfOut[47] = 1.224744871391589*volIn[111]+0.7071067811865475*volIn[102] 
   surfOut[48] = 1.224744871391589*volIn[112]+0.7071067811865475*volIn[106] 
end 
_M[2][2].lower = function (volIn, surfOut) 
   surfOut[1] = 1.58113883008419*volIn[18]-1.224744871391589*volIn[3]+0.7071067811865475*volIn[1] 
   surfOut[2] = 1.58113883008419*volIn[33]-1.224744871391589*volIn[7]+0.7071067811865475*volIn[2] 
   surfOut[3] = 1.58113883008419*volIn[35]-1.224744871391589*volIn[9]+0.7071067811865475*volIn[4] 
   surfOut[4] = 1.58113883008419*volIn[39]-1.224744871391589*volIn[11]+0.7071067811865475*volIn[5] 
   surfOut[5] = 1.58113883008419*volIn[45]-1.224744871391589*volIn[14]+0.7071067811865475*volIn[6] 
   surfOut[6] = 1.58113883008419*volIn[58]-1.224744871391589*volIn[22]+0.7071067811865475*volIn[8] 
   surfOut[7] = 1.58113883008419*volIn[61]-1.224744871391589*volIn[23]+0.7071067811865475*volIn[10] 
   surfOut[8] = 1.58113883008419*volIn[63]-1.224744871391589*volIn[25]+0.7071067811865475*volIn[12] 
   surfOut[9] = 1.58113883008419*volIn[70]-1.224744871391589*volIn[26]+0.7071067811865475*volIn[13] 
   surfOut[10] = 1.58113883008419*volIn[72]-1.224744871391589*volIn[28]+0.7071067811865475*volIn[15] 
   surfOut[11] = 1.58113883008419*volIn[76]-1.224744871391589*volIn[30]+0.7071067811865475*volIn[16] 
   surfOut[12] = 0.7071067811865475*volIn[17]-1.224744871391589*volIn[32] 
   surfOut[13] = 0.7071067811865475*volIn[19]-1.224744871391589*volIn[37] 
   surfOut[14] = 0.7071067811865475*volIn[20]-1.224744871391589*volIn[42] 
   surfOut[15] = 0.7071067811865475*volIn[21]-1.224744871391589*volIn[49] 
   surfOut[16] = 1.58113883008419*volIn[89]-1.224744871391589*volIn[52]+0.7071067811865475*volIn[24] 
   surfOut[17] = 1.58113883008419*volIn[93]-1.224744871391589*volIn[53]+0.7071067811865475*volIn[27] 
   surfOut[18] = 1.58113883008419*volIn[96]-1.224744871391589*volIn[54]+0.7071067811865475*volIn[29] 
   surfOut[19] = 1.58113883008419*volIn[98]-1.224744871391589*volIn[56]+0.7071067811865475*volIn[31] 
   surfOut[20] = 0.7071067811865475*volIn[34]-1.224744871391589*volIn[57] 
   surfOut[21] = 0.7071067811865475*volIn[36]-1.224744871391589*volIn[59] 
   surfOut[22] = 0.7071067811865475*volIn[38]-1.224744871391589*volIn[60] 
   surfOut[23] = 0.7071067811865475*volIn[40]-1.224744871391589*volIn[65] 
   surfOut[24] = 0.7071067811865475*volIn[41]-1.224744871391589*volIn[66] 
   surfOut[25] = 0.7071067811865475*volIn[43]-1.224744871391589*volIn[68] 
   surfOut[26] = 0.7071067811865475*volIn[44]-1.224744871391589*volIn[69] 
   surfOut[27] = 0.7071067811865475*volIn[46]-1.224744871391589*volIn[74] 
   surfOut[28] = 0.7071067811865475*volIn[47]-1.224744871391589*volIn[79] 
   surfOut[29] = 0.7071067811865475*volIn[48]-1.224744871391589*volIn[81] 
   surfOut[30] = 0.7071067811865475*volIn[50]-1.224744871391589*volIn[83] 
   surfOut[31] = 0.7071067811865475*volIn[51]-1.224744871391589*volIn[85] 
   surfOut[32] = 1.58113883008419*volIn[109]-1.224744871391589*volIn[87]+0.7071067811865475*volIn[55] 
   surfOut[33] = 0.7071067811865475*volIn[62]-1.224744871391589*volIn[88] 
   surfOut[34] = 0.7071067811865475*volIn[64]-1.224744871391589*volIn[90] 
   surfOut[35] = 0.7071067811865475*volIn[67]-1.224744871391589*volIn[91] 
   surfOut[36] = 0.7071067811865475*volIn[71]-1.224744871391589*volIn[92] 
   surfOut[37] = 0.7071067811865475*volIn[73]-1.224744871391589*volIn[94] 
   surfOut[38] = 0.7071067811865475*volIn[75]-1.224744871391589*volIn[95] 
   surfOut[39] = 0.7071067811865475*volIn[77]-1.224744871391589*volIn[100] 
   surfOut[40] = 0.7071067811865475*volIn[78]-1.224744871391589*volIn[101] 
   surfOut[41] = 0.7071067811865475*volIn[80]-1.224744871391589*volIn[103] 
   surfOut[42] = 0.7071067811865475*volIn[82]-1.224744871391589*volIn[104] 
   surfOut[43] = 0.7071067811865475*volIn[84]-1.224744871391589*volIn[105] 
   surfOut[44] = 0.7071067811865475*volIn[86]-1.224744871391589*volIn[107] 
   surfOut[45] = 0.7071067811865475*volIn[97]-1.224744871391589*volIn[108] 
   surfOut[46] = 0.7071067811865475*volIn[99]-1.224744871391589*volIn[110] 
   surfOut[47] = 0.7071067811865475*volIn[102]-1.224744871391589*volIn[111] 
   surfOut[48] = 0.7071067811865475*volIn[106]-1.224744871391589*volIn[112] 
end 

--    dir 3 
_M[2][3] = {} 
_M[2][3].upper = function (volIn, surfOut) 
   surfOut[1] = 1.58113883008419*volIn[19]+1.224744871391589*volIn[4]+0.7071067811865475*volIn[1] 
   surfOut[2] = 1.58113883008419*volIn[36]+1.224744871391589*volIn[8]+0.7071067811865475*volIn[2] 
   surfOut[3] = 1.58113883008419*volIn[37]+1.224744871391589*volIn[9]+0.7071067811865475*volIn[3] 
   surfOut[4] = 1.58113883008419*volIn[40]+1.224744871391589*volIn[12]+0.7071067811865475*volIn[5] 
   surfOut[5] = 1.58113883008419*volIn[46]+1.224744871391589*volIn[15]+0.7071067811865475*volIn[6] 
   surfOut[6] = 1.58113883008419*volIn[59]+1.224744871391589*volIn[22]+0.7071067811865475*volIn[7] 
   surfOut[7] = 1.58113883008419*volIn[64]+1.224744871391589*volIn[24]+0.7071067811865475*volIn[10] 
   surfOut[8] = 1.58113883008419*volIn[65]+1.224744871391589*volIn[25]+0.7071067811865475*volIn[11] 
   surfOut[9] = 1.58113883008419*volIn[73]+1.224744871391589*volIn[27]+0.7071067811865475*volIn[13] 
   surfOut[10] = 1.58113883008419*volIn[74]+1.224744871391589*volIn[28]+0.7071067811865475*volIn[14] 
   surfOut[11] = 1.58113883008419*volIn[77]+1.224744871391589*volIn[31]+0.7071067811865475*volIn[16] 
   surfOut[12] = 1.224744871391589*volIn[34]+0.7071067811865475*volIn[17] 
   surfOut[13] = 1.224744871391589*volIn[35]+0.7071067811865475*volIn[18] 
   surfOut[14] = 1.224744871391589*volIn[43]+0.7071067811865475*volIn[20] 
   surfOut[15] = 1.224744871391589*volIn[50]+0.7071067811865475*volIn[21] 
   surfOut[16] = 1.58113883008419*volIn[90]+1.224744871391589*volIn[52]+0.7071067811865475*volIn[23] 
   surfOut[17] = 1.58113883008419*volIn[94]+1.224744871391589*volIn[53]+0.7071067811865475*volIn[26] 
   surfOut[18] = 1.58113883008419*volIn[99]+1.224744871391589*volIn[55]+0.7071067811865475*volIn[29] 
   surfOut[19] = 1.58113883008419*volIn[100]+1.224744871391589*volIn[56]+0.7071067811865475*volIn[30] 
   surfOut[20] = 1.224744871391589*volIn[57]+0.7071067811865475*volIn[32] 
   surfOut[21] = 1.224744871391589*volIn[58]+0.7071067811865475*volIn[33] 
   surfOut[22] = 1.224744871391589*volIn[62]+0.7071067811865475*volIn[38] 
   surfOut[23] = 1.224744871391589*volIn[63]+0.7071067811865475*volIn[39] 
   surfOut[24] = 1.224744871391589*volIn[67]+0.7071067811865475*volIn[41] 
   surfOut[25] = 1.224744871391589*volIn[68]+0.7071067811865475*volIn[42] 
   surfOut[26] = 1.224744871391589*volIn[71]+0.7071067811865475*volIn[44] 
   surfOut[27] = 1.224744871391589*volIn[72]+0.7071067811865475*volIn[45] 
   surfOut[28] = 1.224744871391589*volIn[80]+0.7071067811865475*volIn[47] 
   surfOut[29] = 1.224744871391589*volIn[82]+0.7071067811865475*volIn[48] 
   surfOut[30] = 1.224744871391589*volIn[83]+0.7071067811865475*volIn[49] 
   surfOut[31] = 1.224744871391589*volIn[86]+0.7071067811865475*volIn[51] 
   surfOut[32] = 1.58113883008419*volIn[110]+1.224744871391589*volIn[87]+0.7071067811865475*volIn[54] 
   surfOut[33] = 1.224744871391589*volIn[88]+0.7071067811865475*volIn[60] 
   surfOut[34] = 1.224744871391589*volIn[89]+0.7071067811865475*volIn[61] 
   surfOut[35] = 1.224744871391589*volIn[91]+0.7071067811865475*volIn[66] 
   surfOut[36] = 1.224744871391589*volIn[92]+0.7071067811865475*volIn[69] 
   surfOut[37] = 1.224744871391589*volIn[93]+0.7071067811865475*volIn[70] 
   surfOut[38] = 1.224744871391589*volIn[97]+0.7071067811865475*volIn[75] 
   surfOut[39] = 1.224744871391589*volIn[98]+0.7071067811865475*volIn[76] 
   surfOut[40] = 1.224744871391589*volIn[102]+0.7071067811865475*volIn[78] 
   surfOut[41] = 1.224744871391589*volIn[103]+0.7071067811865475*volIn[79] 
   surfOut[42] = 1.224744871391589*volIn[104]+0.7071067811865475*volIn[81] 
   surfOut[43] = 1.224744871391589*volIn[106]+0.7071067811865475*volIn[84] 
   surfOut[44] = 1.224744871391589*volIn[107]+0.7071067811865475*volIn[85] 
   surfOut[45] = 1.224744871391589*volIn[108]+0.7071067811865475*volIn[95] 
   surfOut[46] = 1.224744871391589*volIn[109]+0.7071067811865475*volIn[96] 
   surfOut[47] = 1.224744871391589*volIn[111]+0.7071067811865475*volIn[101] 
   surfOut[48] = 1.224744871391589*volIn[112]+0.7071067811865475*volIn[105] 
end 
_M[2][3].lower = function (volIn, surfOut) 
   surfOut[1] = 1.58113883008419*volIn[19]-1.224744871391589*volIn[4]+0.7071067811865475*volIn[1] 
   surfOut[2] = 1.58113883008419*volIn[36]-1.224744871391589*volIn[8]+0.7071067811865475*volIn[2] 
   surfOut[3] = 1.58113883008419*volIn[37]-1.224744871391589*volIn[9]+0.7071067811865475*volIn[3] 
   surfOut[4] = 1.58113883008419*volIn[40]-1.224744871391589*volIn[12]+0.7071067811865475*volIn[5] 
   surfOut[5] = 1.58113883008419*volIn[46]-1.224744871391589*volIn[15]+0.7071067811865475*volIn[6] 
   surfOut[6] = 1.58113883008419*volIn[59]-1.224744871391589*volIn[22]+0.7071067811865475*volIn[7] 
   surfOut[7] = 1.58113883008419*volIn[64]-1.224744871391589*volIn[24]+0.7071067811865475*volIn[10] 
   surfOut[8] = 1.58113883008419*volIn[65]-1.224744871391589*volIn[25]+0.7071067811865475*volIn[11] 
   surfOut[9] = 1.58113883008419*volIn[73]-1.224744871391589*volIn[27]+0.7071067811865475*volIn[13] 
   surfOut[10] = 1.58113883008419*volIn[74]-1.224744871391589*volIn[28]+0.7071067811865475*volIn[14] 
   surfOut[11] = 1.58113883008419*volIn[77]-1.224744871391589*volIn[31]+0.7071067811865475*volIn[16] 
   surfOut[12] = 0.7071067811865475*volIn[17]-1.224744871391589*volIn[34] 
   surfOut[13] = 0.7071067811865475*volIn[18]-1.224744871391589*volIn[35] 
   surfOut[14] = 0.7071067811865475*volIn[20]-1.224744871391589*volIn[43] 
   surfOut[15] = 0.7071067811865475*volIn[21]-1.224744871391589*volIn[50] 
   surfOut[16] = 1.58113883008419*volIn[90]-1.224744871391589*volIn[52]+0.7071067811865475*volIn[23] 
   surfOut[17] = 1.58113883008419*volIn[94]-1.224744871391589*volIn[53]+0.7071067811865475*volIn[26] 
   surfOut[18] = 1.58113883008419*volIn[99]-1.224744871391589*volIn[55]+0.7071067811865475*volIn[29] 
   surfOut[19] = 1.58113883008419*volIn[100]-1.224744871391589*volIn[56]+0.7071067811865475*volIn[30] 
   surfOut[20] = 0.7071067811865475*volIn[32]-1.224744871391589*volIn[57] 
   surfOut[21] = 0.7071067811865475*volIn[33]-1.224744871391589*volIn[58] 
   surfOut[22] = 0.7071067811865475*volIn[38]-1.224744871391589*volIn[62] 
   surfOut[23] = 0.7071067811865475*volIn[39]-1.224744871391589*volIn[63] 
   surfOut[24] = 0.7071067811865475*volIn[41]-1.224744871391589*volIn[67] 
   surfOut[25] = 0.7071067811865475*volIn[42]-1.224744871391589*volIn[68] 
   surfOut[26] = 0.7071067811865475*volIn[44]-1.224744871391589*volIn[71] 
   surfOut[27] = 0.7071067811865475*volIn[45]-1.224744871391589*volIn[72] 
   surfOut[28] = 0.7071067811865475*volIn[47]-1.224744871391589*volIn[80] 
   surfOut[29] = 0.7071067811865475*volIn[48]-1.224744871391589*volIn[82] 
   surfOut[30] = 0.7071067811865475*volIn[49]-1.224744871391589*volIn[83] 
   surfOut[31] = 0.7071067811865475*volIn[51]-1.224744871391589*volIn[86] 
   surfOut[32] = 1.58113883008419*volIn[110]-1.224744871391589*volIn[87]+0.7071067811865475*volIn[54] 
   surfOut[33] = 0.7071067811865475*volIn[60]-1.224744871391589*volIn[88] 
   surfOut[34] = 0.7071067811865475*volIn[61]-1.224744871391589*volIn[89] 
   surfOut[35] = 0.7071067811865475*volIn[66]-1.224744871391589*volIn[91] 
   surfOut[36] = 0.7071067811865475*volIn[69]-1.224744871391589*volIn[92] 
   surfOut[37] = 0.7071067811865475*volIn[70]-1.224744871391589*volIn[93] 
   surfOut[38] = 0.7071067811865475*volIn[75]-1.224744871391589*volIn[97] 
   surfOut[39] = 0.7071067811865475*volIn[76]-1.224744871391589*volIn[98] 
   surfOut[40] = 0.7071067811865475*volIn[78]-1.224744871391589*volIn[102] 
   surfOut[41] = 0.7071067811865475*volIn[79]-1.224744871391589*volIn[103] 
   surfOut[42] = 0.7071067811865475*volIn[81]-1.224744871391589*volIn[104] 
   surfOut[43] = 0.7071067811865475*volIn[84]-1.224744871391589*volIn[106] 
   surfOut[44] = 0.7071067811865475*volIn[85]-1.224744871391589*volIn[107] 
   surfOut[45] = 0.7071067811865475*volIn[95]-1.224744871391589*volIn[108] 
   