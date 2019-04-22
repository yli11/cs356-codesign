

#include <HERA.h>

void HERA_main()
{

 // Saving state of processor
 LABEL(save_state)

    DLABEL(config_store) // Blocking out memory to store current config. information
      DSKIP(50)

    CBON()

    // Adding test values to registers
    SET(R3, 5)
    SET(R4, 10)
    SET(R6, 15)
    SET(R7, 20)
    SET(R8, 25)
    SET(R9, 30)
    SET(R10, 35)

    SAVEF(R1) // Flags stored in R1
    SET(R2, config_store) // Address in memeory where all information will be stored

    // Saving flags
    STORE(R2, 0, R1)
    INC(R2, 1)

    // Saving registers
    // R3
    STORE(R2, 0, R3)
    INC(R2, 1)

    // R4
    STORE(R2, 0, R4)
    INC(R2, 1)

    // R5
    STORE(R2, 0, R5)
    INC(R2, 1)

    // R6
    STORE(R2, 0, R6)
    INC(R2, 1)

    // R7
    STORE(R2, 0, R7)
    INC(R2, 1)

    // R8
    STORE(R2, 0, R8)
    INC(R2, 1)

    // R9
    STORE(R2, 0, R9)
    INC(R2, 1)

    // R10
    STORE(R2, 0, R9)
    INC(R2, 1)

    // R1
    STORE(R2, 0, R1)
    INC(R2, 1)

    // R2
    STORE(R2, 0, R2)
    INC(R2, 1)

    // Save PC (?)

    // Branch to interrupt
    // BR(b)


  HALT()


}
