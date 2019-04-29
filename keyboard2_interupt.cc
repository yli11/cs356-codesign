#include <HERA.h>

void HERA_main()
{//save everything because this is an interupt procedure
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
  
  //check if keyboard 1 has input, then store it to memory if it is not 0. If it is a new line char (0a), then store it to memory start printing everything
  //DLABEL(buffer_start) //creates a variable, buffer_start, which is a memory location
  CBON()
  SETLO(R10, 0)
  OPCODE(0x2a01) //unique opcode to check if keyboard 1 has input, and puts it in r10. Does not set any flags
  SET(R1, 0x4000)//store the length of the string here, and the string itself starting at 0x4001 (LP string)
  LOAD(R4, 0, R1) //SET R4 to the number of chars so far
  INC(R4, 1)
  STORE(R4, 0, R1)
  ADD(R1, R1, R4)
  STORE(R10, 0, R1)
 
  SETLO(R3, 0x0a)
  CMP(R10, R3) //check if it is a new line character
  BZR(DEAL_WITH_NEWLINE)
  BRR(restore)
  LABEL(DEAL_WITH_NEWLINE)
  STORE(R0, 0, 0x4000)//don't care about the length anymore because we are printing now
  SET(R1, 0x4001)//the start of the string itself
    LABEL(print_loop)
       LOAD(R2, 0, R1)
       ADD(R0, R0, R2)  //Use ADD(R0,R0,R2) to output to screen2
  STORE(R0, 0, R1)
  CMP(R2, R3) //if is new line, we are done
       BZR(restore)
       INC(R1, 1)
    BRR(print_loop)




  
LABEL(restore)

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
  RTI()

}
