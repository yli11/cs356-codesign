# CS356 Co-Design of an I/O System
Green Team: Carter Langen, Mikal Hayden-Gates, Yutong Li, Henry Plambeck, Nanda Bhushan

## Design Description
Our output function `PUTCHAR_2` is defined using the opcode `ADD(R0,R0,R1)`. The Logisim circuit will recogize this opcode and enable write to TTY. The character printed is the ASCII character corresponding to the lower 7 bits of the result of the addition.

2a00 = ask the keyboard for ascii char from keyboard 1
2a01 = ask the keyboard for ascii char from keyboard 2
Both of these store the resulting character in R10

New line character 0A

## Design Description:
Check for value w/ OPCODE(0x2a01) → if not zero, store R10 into memory; return otherwise.  → SUB ascii value of \newline from R10 →  BZ(print_key2) → branch back to SET(R10,0)
print_key2 is the function that loops through the values starting from (INPUT2), print after reversing case or whatever. Remember to clear each memory cell after printing, perhaps STORE(R0, address). (this is all pseudocode)

## Implmentation:
We have a long loop that adds some numbers together and pretends to be useful, and everytime the loop ends, it calls two functions. These functions ask the keyboards if they have a character, and then do what they are supposed to do. 1 prints right away, as per the spefications, 2 stores in memory and will print all the charaters once newline has been pressed. Both keyboards will send their input to R10, but they will only send them when asked. 
Keyboard 2 is weird. To prevent character loss, we use R1 to keep track of the next open memory address. To print, we then reset R1, and loop through memory until we reach a new line char (0a). Then we re-reset R1. As we print, we also wipe the char from memory so that we do not over print.

