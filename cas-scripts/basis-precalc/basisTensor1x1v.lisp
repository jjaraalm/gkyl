;;; -*- Mode: LISP; package:maxima; syntax:common-lisp; -*- 
(in-package :maxima)
(DSKSETQ |$varsC| '((MLIST SIMP) $X)) 
(ADD2LNC '|$varsC| $VALUES) 
(DSKSETQ |$varsP| '((MLIST SIMP) $X $VX)) 
(ADD2LNC '|$varsP| $VALUES) 
(DSKSETQ |$basisC|
         '((MLIST SIMP
            (10.
             "/Users/JunoRavin/gkyl/cas-scripts/basis-precalc/basis-pre-calc.mac"
             SRC |$writeBasisToFile| 7.))
           ((MLIST SIMP
             (32. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
              |$gsOrthoNorm| 30.))
            ((MEXPT SIMP) 2. ((RAT SIMP) -1. 2.))
            ((MTIMES SIMP) ((MEXPT SIMP) 2. ((RAT SIMP) -1. 2.))
             ((MEXPT SIMP) 3. ((RAT SIMP) 1. 2.)) $X))
           ((MLIST SIMP
             (32. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
              |$gsOrthoNorm| 30.))
            ((MEXPT SIMP) 2. ((RAT SIMP) -1. 2.))
            ((MTIMES SIMP) ((MEXPT SIMP) 2. ((RAT SIMP) -1. 2.))
             ((MEXPT SIMP) 3. ((RAT SIMP) 1. 2.)) $X)
            ((MTIMES SIMP) 3. ((MEXPT SIMP) 2. ((RAT SIMP) -3. 2.))
             ((MEXPT SIMP) 5. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
              ((MEXPT SIMP
                (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                 |$calcPowers| 62.))
               $X 2.))))
           ((MLIST SIMP
             (32. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
              |$gsOrthoNorm| 30.))
            ((MEXPT SIMP) 2. ((RAT SIMP) -1. 2.))
            ((MTIMES SIMP) ((MEXPT SIMP) 2. ((RAT SIMP) -1. 2.))
             ((MEXPT SIMP) 3. ((RAT SIMP) 1. 2.)) $X)
            ((MTIMES SIMP) 3. ((MEXPT SIMP) 2. ((RAT SIMP) -3. 2.))
             ((MEXPT SIMP) 5. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
              ((MEXPT SIMP
                (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                 |$calcPowers| 62.))
               $X 2.)))
            ((MTIMES SIMP) 5. ((MEXPT SIMP) 2. ((RAT SIMP) -3. 2.))
             ((MEXPT SIMP) 7. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $X)
              ((MEXPT SIMP
                (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                 |$calcPowers| 62.))
               $X 3.))))
           ((MLIST SIMP
             (32. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
              |$gsOrthoNorm| 30.))
            ((MEXPT SIMP) 2. ((RAT SIMP) -1. 2.))
            ((MTIMES SIMP) ((MEXPT SIMP) 2. ((RAT SIMP) -1. 2.))
             ((MEXPT SIMP) 3. ((RAT SIMP) 1. 2.)) $X)
            ((MTIMES SIMP) 3. ((MEXPT SIMP) 2. ((RAT SIMP) -3. 2.))
             ((MEXPT SIMP) 5. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
              ((MEXPT SIMP
                (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                 |$calcPowers| 62.))
               $X 2.)))
            ((MTIMES SIMP) 5. ((MEXPT SIMP) 2. ((RAT SIMP) -3. 2.))
             ((MEXPT SIMP) 7. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $X)
              ((MEXPT SIMP
                (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                 |$calcPowers| 62.))
               $X 3.)))
            ((MTIMES SIMP) 105. ((MEXPT SIMP) 2. ((RAT SIMP) -7. 2.))
             ((MPLUS SIMP) ((RAT SIMP) -1. 5.)
              ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $X 2.)))
              ((MEXPT SIMP
                (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                 |$calcPowers| 62.))
               $X 4.)))))) 
(ADD2LNC '|$basisC| $VALUES) 
(DSKSETQ |$basisP|
         '((MLIST SIMP
            (10.
             "/Users/JunoRavin/gkyl/cas-scripts/basis-precalc/basis-pre-calc.mac"
             SRC |$writeBasisToFile| 7.))
           ((MLIST SIMP
             (32. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
              |$gsOrthoNorm| 30.))
            ((RAT SIMP) 1. 2.)
            ((MTIMES SIMP) ((RAT SIMP) 1. 2.)
             ((MEXPT SIMP) 3. ((RAT SIMP) 1. 2.)) $X)
            ((MTIMES SIMP) ((RAT SIMP) 1. 2.)
             ((MEXPT SIMP) 3. ((RAT SIMP) 1. 2.)) $VX)
            ((MTIMES SIMP) ((RAT SIMP) 3. 2.) $VX $X))
           ((MLIST SIMP
             (32. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
              |$gsOrthoNorm| 30.))
            ((RAT SIMP) 1. 2.)
            ((MTIMES SIMP) ((RAT SIMP) 1. 2.)
             ((MEXPT SIMP) 3. ((RAT SIMP) 1. 2.)) $X)
            ((MTIMES SIMP) ((RAT SIMP) 1. 2.)
             ((MEXPT SIMP) 3. ((RAT SIMP) 1. 2.)) $VX)
            ((MTIMES SIMP) ((RAT SIMP) 3. 2.) $VX $X)
            ((MTIMES SIMP) ((RAT SIMP) 3. 4.)
             ((MEXPT SIMP) 5. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
              ((MEXPT SIMP
                (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                 |$calcPowers| 62.))
               $X 2.)))
            ((MTIMES SIMP) ((RAT SIMP) 3. 4.)
             ((MEXPT SIMP) 5. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
              ((MEXPT SIMP
                (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                 |$calcPowers| 62.))
               $VX 2.)))
            ((MTIMES SIMP) ((RAT SIMP) 3. 4.)
             ((MEXPT SIMP) 15. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 3.) $VX)
              ((MTIMES SIMP) $VX
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 2.))))
            ((MTIMES SIMP) ((RAT SIMP) 3. 4.)
             ((MEXPT SIMP) 15. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 3.) $X)
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 2.)
               $X)))
            ((MTIMES SIMP) ((RAT SIMP) 45. 8.)
             ((MPLUS SIMP) ((RAT SIMP) -1. 9.)
              ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $VX 2.)))
              ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $X 2.)))
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 2.)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 2.)))))
           ((MLIST SIMP
             (32. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
              |$gsOrthoNorm| 30.))
            ((RAT SIMP) 1. 2.)
            ((MTIMES SIMP) ((RAT SIMP) 1. 2.)
             ((MEXPT SIMP) 3. ((RAT SIMP) 1. 2.)) $X)
            ((MTIMES SIMP) ((RAT SIMP) 1. 2.)
             ((MEXPT SIMP) 3. ((RAT SIMP) 1. 2.)) $VX)
            ((MTIMES SIMP) ((RAT SIMP) 3. 2.) $VX $X)
            ((MTIMES SIMP) ((RAT SIMP) 3. 4.)
             ((MEXPT SIMP) 5. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
              ((MEXPT SIMP
                (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                 |$calcPowers| 62.))
               $X 2.)))
            ((MTIMES SIMP) ((RAT SIMP) 3. 4.)
             ((MEXPT SIMP) 5. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
              ((MEXPT SIMP
                (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                 |$calcPowers| 62.))
               $VX 2.)))
            ((MTIMES SIMP) ((RAT SIMP) 3. 4.)
             ((MEXPT SIMP) 15. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 3.) $VX)
              ((MTIMES SIMP) $VX
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 2.))))
            ((MTIMES SIMP) ((RAT SIMP) 3. 4.)
             ((MEXPT SIMP) 15. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 3.) $X)
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 2.)
               $X)))
            ((MTIMES SIMP) ((RAT SIMP) 5. 4.)
             ((MEXPT SIMP) 7. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $X)
              ((MEXPT SIMP
                (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                 |$calcPowers| 62.))
               $X 3.)))
            ((MTIMES SIMP) ((RAT SIMP) 5. 4.)
             ((MEXPT SIMP) 7. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $VX)
              ((MEXPT SIMP
                (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                 |$calcPowers| 62.))
               $VX 3.)))
            ((MTIMES SIMP) ((RAT SIMP) 45. 8.)
             ((MPLUS SIMP) ((RAT SIMP) -1. 9.)
              ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $VX 2.)))
              ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $X 2.)))
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 2.)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 2.))))
            ((MTIMES SIMP) ((RAT SIMP) 5. 4.)
             ((MEXPT SIMP) 21. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $VX $X)
              ((MTIMES SIMP) $VX
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 3.))))
            ((MTIMES SIMP) ((RAT SIMP) 5. 4.)
             ((MEXPT SIMP) 21. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $VX $X)
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 3.)
               $X)))
            ((MTIMES SIMP) ((RAT SIMP) 15. 8.)
             ((MEXPT SIMP) 35. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 5.) $X)
              ((MTIMES SIMP) ((RAT SIMP) -3. 5.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 3.) $X)
                ((MTIMES SIMP)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $VX 2.)
                 $X)))
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 2.)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 3.))
              ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $X)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $X 3.)))))
            ((MTIMES SIMP) ((RAT SIMP) 15. 8.)
             ((MEXPT SIMP) 35. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 5.) $VX)
              ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $VX)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $VX 3.)))
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 3.)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 2.))
              ((MTIMES SIMP) ((RAT SIMP) -3. 5.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 3.) $VX)
                ((MTIMES SIMP) $VX
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $X 2.))))))
            ((MTIMES SIMP) ((RAT SIMP) 175. 8.)
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -9. 25.) $VX $X)
              ((MTIMES SIMP) ((RAT SIMP) -3. 5.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $VX $X)
                ((MTIMES SIMP)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $VX 3.)
                 $X)))
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 3.)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 3.))
              ((MTIMES SIMP) ((RAT SIMP) -3. 5.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $VX $X)
                ((MTIMES SIMP) $VX
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $X 3.)))))))
           ((MLIST SIMP
             (32. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
              |$gsOrthoNorm| 30.))
            ((RAT SIMP) 1. 2.)
            ((MTIMES SIMP) ((RAT SIMP) 1. 2.)
             ((MEXPT SIMP) 3. ((RAT SIMP) 1. 2.)) $X)
            ((MTIMES SIMP) ((RAT SIMP) 1. 2.)
             ((MEXPT SIMP) 3. ((RAT SIMP) 1. 2.)) $VX)
            ((MTIMES SIMP) ((RAT SIMP) 3. 2.) $VX $X)
            ((MTIMES SIMP) ((RAT SIMP) 3. 4.)
             ((MEXPT SIMP) 5. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
              ((MEXPT SIMP
                (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                 |$calcPowers| 62.))
               $X 2.)))
            ((MTIMES SIMP) ((RAT SIMP) 3. 4.)
             ((MEXPT SIMP) 5. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
              ((MEXPT SIMP
                (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                 |$calcPowers| 62.))
               $VX 2.)))
            ((MTIMES SIMP) ((RAT SIMP) 3. 4.)
             ((MEXPT SIMP) 15. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 3.) $VX)
              ((MTIMES SIMP) $VX
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 2.))))
            ((MTIMES SIMP) ((RAT SIMP) 3. 4.)
             ((MEXPT SIMP) 15. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 3.) $X)
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 2.)
               $X)))
            ((MTIMES SIMP) ((RAT SIMP) 5. 4.)
             ((MEXPT SIMP) 7. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $X)
              ((MEXPT SIMP
                (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                 |$calcPowers| 62.))
               $X 3.)))
            ((MTIMES SIMP) ((RAT SIMP) 5. 4.)
             ((MEXPT SIMP) 7. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $VX)
              ((MEXPT SIMP
                (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                 |$calcPowers| 62.))
               $VX 3.)))
            ((MTIMES SIMP) ((RAT SIMP) 45. 8.)
             ((MPLUS SIMP) ((RAT SIMP) -1. 9.)
              ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $VX 2.)))
              ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $X 2.)))
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 2.)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 2.))))
            ((MTIMES SIMP) ((RAT SIMP) 5. 4.)
             ((MEXPT SIMP) 21. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $VX $X)
              ((MTIMES SIMP) $VX
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 3.))))
            ((MTIMES SIMP) ((RAT SIMP) 5. 4.)
             ((MEXPT SIMP) 21. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $VX $X)
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 3.)
               $X)))
            ((MTIMES SIMP) ((RAT SIMP) 105. 16.)
             ((MPLUS SIMP) ((RAT SIMP) -1. 5.)
              ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $X 2.)))
              ((MEXPT SIMP
                (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                 |$calcPowers| 62.))
               $X 4.)))
            ((MTIMES SIMP) ((RAT SIMP) 105. 16.)
             ((MPLUS SIMP) ((RAT SIMP) -1. 5.)
              ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $VX 2.)))
              ((MEXPT SIMP
                (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                 |$calcPowers| 62.))
               $VX 4.)))
            ((MTIMES SIMP) ((RAT SIMP) 15. 8.)
             ((MEXPT SIMP) 35. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 5.) $X)
              ((MTIMES SIMP) ((RAT SIMP) -3. 5.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 3.) $X)
                ((MTIMES SIMP)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $VX 2.)
                 $X)))
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 2.)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 3.))
              ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $X)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $X 3.)))))
            ((MTIMES SIMP) ((RAT SIMP) 15. 8.)
             ((MEXPT SIMP) 35. ((RAT SIMP) 1. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 5.) $VX)
              ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $VX)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $VX 3.)))
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 3.)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 2.))
              ((MTIMES SIMP) ((RAT SIMP) -3. 5.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 3.) $VX)
                ((MTIMES SIMP) $VX
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $X 2.))))))
            ((MTIMES SIMP) ((RAT SIMP) 35. 16.)
             ((MEXPT SIMP) 3. ((RAT SIMP) 3. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 5.) $VX)
              ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 3.) $VX)
                ((MTIMES SIMP) $VX
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $X 2.))))
              ((MTIMES SIMP) $VX
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 4.))))
            ((MTIMES SIMP) ((RAT SIMP) 35. 16.)
             ((MEXPT SIMP) 3. ((RAT SIMP) 3. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 5.) $X)
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 4.)
               $X)
              ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 3.) $X)
                ((MTIMES SIMP)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $VX 2.)
                 $X)))))
            ((MTIMES SIMP) ((RAT SIMP) 175. 8.)
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -9. 25.) $VX $X)
              ((MTIMES SIMP) ((RAT SIMP) -3. 5.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $VX $X)
                ((MTIMES SIMP)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $VX 3.)
                 $X)))
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 3.)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 3.))
              ((MTIMES SIMP) ((RAT SIMP) -3. 5.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $VX $X)
                ((MTIMES SIMP) $VX
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $X 3.))))))
            ((MTIMES SIMP) ((RAT SIMP) 63. 32.)
             ((MEXPT SIMP) 5. ((RAT SIMP) 3. 2.))
             ((MPLUS SIMP) ((RAT SIMP) -1. 15.)
              ((MTIMES SIMP) ((RAT SIMP) -1. 5.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $VX 2.)))
              ((MTIMES SIMP) ((RAT SIMP) -2. 7.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $X 2.)))
              ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 9.)
                ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
                 ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                  ((MEXPT SIMP
                    (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                     SRC |$calcPowers| 62.))
                   $VX 2.)))
                ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
                 ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                  ((MEXPT SIMP
                    (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                     SRC |$calcPowers| 62.))
                   $X 2.)))
                ((MTIMES SIMP)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $VX 2.)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $X 2.))))
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 2.)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 4.))
              ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 5.)
                ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
                 ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                  ((MEXPT SIMP
                    (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                     SRC |$calcPowers| 62.))
                   $X 2.)))
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $X 4.)))))
            ((MTIMES SIMP) ((RAT SIMP) 63. 32.)
             ((MEXPT SIMP) 5. ((RAT SIMP) 3. 2.))
             ((MPLUS SIMP) ((RAT SIMP) -1. 15.)
              ((MTIMES SIMP) ((RAT SIMP) -2. 7.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $VX 2.)))
              ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 5.)
                ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
                 ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                  ((MEXPT SIMP
                    (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                     SRC |$calcPowers| 62.))
                   $VX 2.)))
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $VX 4.)))
              ((MTIMES SIMP) ((RAT SIMP) -1. 5.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $X 2.)))
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 4.)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 2.))
              ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 9.)
                ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
                 ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                  ((MEXPT SIMP
                    (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                     SRC |$calcPowers| 62.))
                   $VX 2.)))
                ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
                 ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                  ((MEXPT SIMP
                    (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                     SRC |$calcPowers| 62.))
                   $X 2.)))
                ((MTIMES SIMP)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $VX 2.)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $X 2.))))))
            ((MTIMES SIMP) ((RAT SIMP) 75. 32.)
             ((MEXPT SIMP) 7. ((RAT SIMP) 3. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 25.) $VX)
              ((MTIMES SIMP) ((RAT SIMP) -1. 5.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $VX)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $VX 3.)))
              ((MTIMES SIMP) ((RAT SIMP) -18. 35.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 3.) $VX)
                ((MTIMES SIMP) $VX
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $X 2.))))
              ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 5.) $VX)
                ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
                 ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $VX)
                  ((MEXPT SIMP
                    (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                     SRC |$calcPowers| 62.))
                   $VX 3.)))
                ((MTIMES SIMP)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $VX 3.)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $X 2.))
                ((MTIMES SIMP) ((RAT SIMP) -3. 5.)
                 ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 3.) $VX)
                  ((MTIMES SIMP) $VX
                   ((MEXPT SIMP
                     (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                      SRC |$calcPowers| 62.))
                    $X 2.))))))
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 3.)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 4.))
              ((MTIMES SIMP) ((RAT SIMP) -3. 5.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 5.) $VX)
                ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
                 ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 3.) $VX)
                  ((MTIMES SIMP) $VX
                   ((MEXPT SIMP
                     (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                      SRC |$calcPowers| 62.))
                    $X 2.))))
                ((MTIMES SIMP) $VX
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $X 4.))))))
            ((MTIMES SIMP) ((RAT SIMP) 75. 32.)
             ((MEXPT SIMP) 7. ((RAT SIMP) 3. 2.))
             ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 25.) $X)
              ((MTIMES SIMP) ((RAT SIMP) -18. 35.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 3.) $X)
                ((MTIMES SIMP)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $VX 2.)
                 $X)))
              ((MTIMES SIMP) ((RAT SIMP) -3. 5.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 5.) $X)
                ((MTIMES SIMP)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $VX 4.)
                 $X)
                ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
                 ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 3.) $X)
                  ((MTIMES SIMP)
                   ((MEXPT SIMP
                     (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                      SRC |$calcPowers| 62.))
                    $VX 2.)
                   $X)))))
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 4.)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 3.))
              ((MTIMES SIMP) ((RAT SIMP) -1. 5.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $X)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $X 3.)))
              ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
               ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 5.) $X)
                ((MTIMES SIMP) ((RAT SIMP) -3. 5.)
                 ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -1. 3.) $X)
                  ((MTIMES SIMP)
                   ((MEXPT SIMP
                     (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                      SRC |$calcPowers| 62.))
                    $VX 2.)
                   $X)))
                ((MTIMES SIMP)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $VX 2.)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $X 3.))
                ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
                 ((MPLUS SIMP) ((MTIMES SIMP) ((RAT SIMP) -3. 5.) $X)
                  ((MEXPT SIMP
                    (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                     SRC |$calcPowers| 62.))
                   $X 3.)))))))
            ((MTIMES SIMP) ((RAT SIMP) 11025. 128.)
             ((MPLUS SIMP) ((RAT SIMP) -1. 25.)
              ((MTIMES SIMP) ((RAT SIMP) -6. 35.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $VX 2.)))
              ((MTIMES SIMP) ((RAT SIMP) -1. 5.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 5.)
                ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
                 ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                  ((MEXPT SIMP
                    (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                     SRC |$calcPowers| 62.))
                   $VX 2.)))
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $VX 4.)))
              ((MTIMES SIMP) ((RAT SIMP) -6. 35.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $X 2.)))
              ((MTIMES SIMP) ((RAT SIMP) -36. 49.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 9.)
                ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
                 ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                  ((MEXPT SIMP
                    (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                     SRC |$calcPowers| 62.))
                   $VX 2.)))
                ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
                 ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                  ((MEXPT SIMP
                    (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                     SRC |$calcPowers| 62.))
                   $X 2.)))
                ((MTIMES SIMP)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $VX 2.)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $X 2.))))
              ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 15.)
                ((MTIMES SIMP) ((RAT SIMP) -2. 7.)
                 ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                  ((MEXPT SIMP
                    (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                     SRC |$calcPowers| 62.))
                   $VX 2.)))
                ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
                 ((MPLUS SIMP) ((RAT SIMP) -1. 5.)
                  ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
                   ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                    ((MEXPT SIMP
                      (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                       SRC |$calcPowers| 62.))
                     $VX 2.)))
                  ((MEXPT SIMP
                    (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                     SRC |$calcPowers| 62.))
                   $VX 4.)))
                ((MTIMES SIMP) ((RAT SIMP) -1. 5.)
                 ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                  ((MEXPT SIMP
                    (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                     SRC |$calcPowers| 62.))
                   $X 2.)))
                ((MTIMES SIMP)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $VX 4.)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $X 2.))
                ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
                 ((MPLUS SIMP) ((RAT SIMP) -1. 9.)
                  ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
                   ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                    ((MEXPT SIMP
                      (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                       SRC |$calcPowers| 62.))
                     $VX 2.)))
                  ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
                   ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                    ((MEXPT SIMP
                      (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                       SRC |$calcPowers| 62.))
                     $X 2.)))
                  ((MTIMES SIMP)
                   ((MEXPT SIMP
                     (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                      SRC |$calcPowers| 62.))
                    $VX 2.)
                   ((MEXPT SIMP
                     (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                      SRC |$calcPowers| 62.))
                    $X 2.))))))
              ((MTIMES SIMP)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $VX 4.)
               ((MEXPT SIMP
                 (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                  |$calcPowers| 62.))
                $X 4.))
              ((MTIMES SIMP) ((RAT SIMP) -1. 5.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 5.)
                ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
                 ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                  ((MEXPT SIMP
                    (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                     SRC |$calcPowers| 62.))
                   $X 2.)))
                ((MEXPT SIMP
                  (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                   |$calcPowers| 62.))
                 $X 4.)))
              ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
               ((MPLUS SIMP) ((RAT SIMP) -1. 15.)
                ((MTIMES SIMP) ((RAT SIMP) -1. 5.)
                 ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                  ((MEXPT SIMP
                    (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                     SRC |$calcPowers| 62.))
                   $VX 2.)))
                ((MTIMES SIMP) ((RAT SIMP) -2. 7.)
                 ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                  ((MEXPT SIMP
                    (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                     SRC |$calcPowers| 62.))
                   $X 2.)))
                ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
                 ((MPLUS SIMP) ((RAT SIMP) -1. 9.)
                  ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
                   ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                    ((MEXPT SIMP
                      (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                       SRC |$calcPowers| 62.))
                     $VX 2.)))
                  ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
                   ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                    ((MEXPT SIMP
                      (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                       SRC |$calcPowers| 62.))
                     $X 2.)))
                  ((MTIMES SIMP)
                   ((MEXPT SIMP
                     (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                      SRC |$calcPowers| 62.))
                    $VX 2.)
                   ((MEXPT SIMP
                     (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                      SRC |$calcPowers| 62.))
                    $X 2.))))
                ((MTIMES SIMP)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $VX 2.)
                 ((MEXPT SIMP
                   (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac" SRC
                    |$calcPowers| 62.))
                  $X 4.))
                ((MTIMES SIMP) ((RAT SIMP) -1. 3.)
                 ((MPLUS SIMP) ((RAT SIMP) -1. 5.)
                  ((MTIMES SIMP) ((RAT SIMP) -6. 7.)
                   ((MPLUS SIMP) ((RAT SIMP) -1. 3.)
                    ((MEXPT SIMP
                      (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                       SRC |$calcPowers| 62.))
                     $X 2.)))
                  ((MEXPT SIMP
                    (62. "/Users/JunoRavin/gkyl/cas-scripts/modal-basis.mac"
                     SRC |$calcPowers| 62.))
                   $X 4.)))))))))) 
(ADD2LNC '|$basisP| $VALUES) 