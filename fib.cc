# include <HERA.h>

void HERA_main()
{

  // VARIABLES
  CBON()
  SET(R2, 3) // n - Where "n" is the nth number in the Fibonacci sequence to be calculated
  SET(R3, 2) // i
  SET(R4, 0) // a
  SET(R5, 1) // b
  SET(R6, 0) // f - Where f is the desired nth number in the Fibonacci sequence
  SET(R7, 1) // Used to check if "n" is 0

  // FUNCTION DEFINITION
  DLABEL(fib_begin)

    SUB(R8, R2, R7) // If R8 == 0, then n <= 1
    BZ(fib_end) 

    DLABEL(loop_begin) // for(i=2; i<=n: i++)

      SUB(R9, R2, R3) // If R9 <= 0, then i<=n
      BZ(loop_end)

        ADD(R6, R4, R5)// f = a + b
        LOAD(R4, 0, R5)// a = b
        LOAD(R5, 0, R6)// b = f
        INC(R3, 1) // Increment loop by 1
        DEC(R2, 1) // Decrement n
        BR(loop_begin)

    DLABEL(loop_end)

  DLABEL(fib_end)

  HALT()

}
