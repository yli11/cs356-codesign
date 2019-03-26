#include <HERA.h>

void HERA_main()
{

  DLABEL(Keyboard_2)
  DSKIP(512)
  CBON()
LABEL(TOP)
  CALL(FP_alt, poll_0)
  SET(R1, Keyboard_2)
  STORE(R4, 0, R15)
  SET(R4, 0)

  CALL(FP_alt, poll_1)
BR(TOP)

  HALT()

  LABEL(poll_0) //check if keyboard 0 has input, then print if it does
   INC(SP, 2)
   STORE(PC_ret, 0, FP)
   STORE(FP_alt, 1, FP)
   OPCODE(0x2a00)
   MOVE(R1, R10)
   BZ(return) //return right away, unless there is a char, then print it to screen one
    SETLO(R10, 0)
    ADD(R0, R0, R1)  //Use ADD(R0,R0,R1) to output to screen 1
    SETLO(R3, 0x0a)
    CMP(R1, R3) //check if it is a new line character
    BZ(return)
    BR(poll_0)
   LABEL(return)
   LOAD(PC_ret, 0, FP)
   LOAD(FP_alt, 1, FP)
   DEC(SP, 2)
   RETURN(FP_alt, PC_ret) //else, if it is null, return








  LABEL(poll_1) //check if keyboard 0 has input, then store it to memory if it is not 0. If it is a new line char (0a), then store it to memory start printing everything
  INC(SP, 2)
  STORE(PC_ret, 0, FP)
  STORE(FP_alt, 1, FP)
  LABEL(L)
  SETLO(R10, 0)
  OPCODE(0x2a01) //unique opcode to check if keyboard 0 has input. Does not set any flags


  MOVE(R2, R10)
  BZ(return_2)

  STORE(R10, 0, R1)
  INC(R1, 1)
  SETLO(R3, 0x0a)
  CMP(R10, R3) //check if it is a new line character
  BZ(DEAL_WITH_NEWLINE)
  BR(L)
   LABEL(DEAL_WITH_NEWLINE)
    SET(R5, 0)
    SET(R1, Keyboard_2)
    LABEL(print_loop)

      LOAD(R2, 0, R1)
       ADD(R0, R0, R2)  //Use ADD(R0,R0,R2) to output to screen2
       CMP(R2, R3)
       BZ(return_2)
       INC(R1, 1)
    BR(print_loop)
  LABEL(return_2)
  LOAD(PC_ret, 0, FP)
  LOAD(FP_alt, 1, FP)
  DEC(SP, 2)
  RETURN(FP_alt, PC_ret)

}
