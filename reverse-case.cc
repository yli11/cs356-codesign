#include <HERA.h>
//#include <HERA-print.h>
//#include <Tiger-stdlib-reg-data.hera>

void HERA_main()
{
 // #include <Tiger-stdlib-reg-data.hera>

  DLABEL(string_var)
  LP_STRING("ThiS Is a DeMO string")
  DLABEL(convert_string)
  DSKIP(20)  //just set it to any arbitrary large number

  CBON()
  SET(R7, 32) // offset
  SET(R2, string_var) // Address in memory of the string (in R2)
  SET(R6, convert_string) // Address in memory of empty space to hold converted string
  LOAD(R3, 0, R2) // length of string_var in R3

  LABEL(loop_begin)
    INC(R2, 1) //Move R2 to indicate the next character
    DEC(R3, 1) // Decrease the count of how many characters remain in string

    BL(loop_end) // End loop if no more characters remain in string

    LOAD(R4, 0, R2) // Loading current character into register (i.e. R4)
    XOR(R1, R7, R4) // Converting to uppercase (then storing in register, R5)
    STORE(R1, 0, R6) // Storing uppercase char into memory

    CALL(R12, PUTCHAR_2)
    //CALL(R12, PUTCHAR_ORD)
    //CALL(R12, print)
    INC(R6, 1)
    BR(loop_begin) // Go back to beginning of the loop

  LABEL(loop_end)
  HALT()

// #include  <Tiger-stdlib-reg.hera>
   LABEL(PUTCHAR_2)
    OPCODE(0xA001)  //Use ADD(R0,R0,R1) to output to screen
    RETURN(R12, Rt)
}