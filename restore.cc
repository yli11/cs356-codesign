

#include <HERA.h>

void HERA_main()
{

 // Saving state of processor
  LOAD(R1, 15, R0)
  RSTRF(R1)
  LOAD(R1, 0, R0)
  LOAD(R2, 1, R0)
  LOAD(R3, 2, R0)
  LOAD(R4, 3, R0)
  LOAD(R5, 4, R0)
  LOAD(R6, 5, R0)
  LOAD(R7, 6, R0)
  LOAD(R8, 7, R0)
  LOAD(R9, 8, R0)
  LOAD(R10, 9, R0)
  LOAD(R11, 10, R0)
  LOAD(R12, 11, R0)
  LOAD(R13, 12, R0)    
  LOAD(R14, 13, R0)  
  LOAD(R15, 14, R0)
  HALT()


}
