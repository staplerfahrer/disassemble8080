#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "disass.h"
#include "fileio.h"
#include "test.h"

int main()
{
    printf("Started...\n");
    
    struct buffer fileBuf = fileToBuffer("invaders.dat");
    char * allAsm = disassemble8080(&fileBuf);
    printf("Finished.\n");
    puts(allAsm);
    printf("%d", strlen(allAsm));
    free(fileBuf.bytes);
    free(allAsm);
    return 0;
}

