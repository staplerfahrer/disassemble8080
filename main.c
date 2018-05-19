#include <stdio.h>
#include "structs.h"
#include "disass.h"
#include "fileio.h"
#include "test.h"

int main() // int argc, char**argv 
{
    printf("Started...\n");
    
    // instructionList();
    unsigned char * romBytes;
    struct buffer fileBuf = fileToBuffer("invaders.dat");
    printf("bufferSize:\t%d\n", fileBuf.length);
    romBytes = fileBuf.bytes;
    printf("%02x\t%02x\t%02x\t%02x\n\n", romBytes[0], romBytes[1], romBytes[2], romBytes[3]);

    //unsigned char * disassembled = 0x00;
    char * allAsm = disassemble8080(&fileBuf);
    printf(allAsm);

    printf("Finished.\n");
    return 0;
}

