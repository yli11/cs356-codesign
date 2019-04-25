

#include <HERA.h>

void HERA_main()
{

 // Saving state of processor
  STORE(R1, 0, R0)
  STORE(R2, 1, R0)
  STORE(R3, 2, R0)
  STORE(R4, 3, R0)
  STORE(R5, 4, R0)
  STORE(R6, 5, R0)
  STORE(R7, 6, R0)
  STORE(R8, 7, R0)
  STORE(R9, 8, R0)
  STORE(R10, 9, R0)
  STORE(R11, 10, R0)
  STORE(R12, 11, R0)
  STORE(R13, 12, R0)    
  STORE(R14, 13, R0)  
  STORE(R15, 14, R0)
  SAVEF(R1)
  STORE(R1, 15, R0)
  HALT()


}
