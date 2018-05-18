#include <stdio.h>
#include "structs.h"
#include "disass.h"
#include "fileio.h"
#include "test.h"

int main() // int argc, char**argv 
{
    // instructionList();
    unsigned char * romBytes;
    struct buffer fileBuf = fileToBuffer("invaders.dat");
    printf("bufferSize:\t%d\n", fileBuf.length);
    romBytes = fileBuf.bytes;
    printf("%02x\t%02x\t%02x\t%02x\n\n", romBytes[0], romBytes[1], romBytes[2], romBytes[3]);

    unsigned char * disassembled = 0x00;
    int pc = 0;
    int i = 0;
    for (i = 0; i < 10; i++) //eof(fileBuf.length, i)
    {
        struct asmLine al = disassemble8080Char(romBytes, pc);
        printf("asm %s    pc %d\n", al.line, al.pc);
        pc = al.pc;
    }
    return 0;
}

