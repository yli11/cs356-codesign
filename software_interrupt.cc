#include <HERA.h>

void HERA_main()
{//save everything because this is an interupt procedure

/*
  // number of threads that are still running
  DLABEL(thread_count)
  DSKIP(10)

  // sample code for creating threads, increment active thread count 
  SET(R1, thread_count)
  SETLO(R2, 2)
  SETLO(R3, 1)
  STORE(R2, 0, R1)
  STORE(R3, 1, R1)
  STORE(R3, 2, R1)
*/

  // main program
  LABEL(main_start)
  SWI(1)
  SWI(2)
  BR(main_start)
  HALT()


LABEL(thread1)
INC(R1, 1)
INC(R3, 1)
INC(R5, 1)
INC(R7, 1)
INC(R9, 1)
BRR(thread1)

LABEL(thread2)
INC(R2, 1)
INC(R4, 1)
INC(R6, 1)
INC(R8, 1)
INC(R10, 1)
BRR(thread2)


LABEL(store1) // store thread 1 data at memory address 0
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

LABEL(store2) // store thread 2 data at memory address 20
  STORE(R1, 16, R0)
  STORE(R2, 17, R0)
  STORE(R3, 18, R0)
  STORE(R4, 19, R0)
  STORE(R5, 20, R0)
  STORE(R6, 21, R0)
  STORE(R7, 22, R0)
  STORE(R8, 23, R0)
  STORE(R9, 24, R0)
  STORE(R10, 25, R0)
  STORE(R11, 27, R0)
  STORE(R12, 27, R0)
  STORE(R13, 28, R0)    
  STORE(R14, 29, R0)  
  STORE(R15, 30, R0)
  SAVEF(R1)
  STORE(R1, 31, R0)

LABEL(restore1)

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

LABEL(restore2)

  LOAD(R1, 31, R0)
  RSTRF(R1)
  LOAD(R1, 16, R0)
  LOAD(R2, 17, R0)
  LOAD(R3, 18, R0)
  LOAD(R4, 19, R0)
  LOAD(R5, 20, R0)
  LOAD(R6, 21, R0)
  LOAD(R7, 22, R0)
  LOAD(R8, 23, R0)
  LOAD(R9, 24, R0)
  LOAD(R10, 25, R0)
  LOAD(R11, 26, R0)
  LOAD(R12, 27, R0)
  LOAD(R13, 28, R0)    
  LOAD(R14, 29, R0)  
  LOAD(R15, 30, R0)
  RTI()

}
