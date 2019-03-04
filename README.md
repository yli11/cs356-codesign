# CS356 Co-Design of an I/O System
Green Team: Carter Langen, Mikal Hayden-Gates, Yutong Li, Henry Plambeck, Nanda Bhushan

## Design Description
Our output function `PUTCHAR_2` is defined using the opcode `ADD(R0,R0,R1)`. The Logisim circuit will recogize this opcode and enable write to TTY. The character printed is the ASCII character corresponding to the lower 7 bits of the result of the addition.
