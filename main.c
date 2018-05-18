#include <stdio.h>
#include "structs.h"
#include "disass.h"
#include "fileio.h"
#include "test.h"

int main() // int argc, char**argv 
{
    // instructionList();
    unsigned char * romBytes = 0x00;
    int bufferSize = fileToBuffer("invaders.dat", romBytes);
    printf("%d", bufferSize);

    unsigned char * disassembled = 0x00;
    struct asmLine al = disassemble8080Char(romBytes, 0x00);
    printf("asm %s    pc %d", al.line, al.pc);
    return 0;
}

