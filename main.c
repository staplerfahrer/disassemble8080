#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"
#include "disass.h"
#include "fileio.h"
#include "test.h"

int main()
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    printf("Started...\n");
    
    struct buffer fileBuf = fileToBuffer("invaders.dat");
    char * allAsm = disassemble8080(&fileBuf);

    printf("Finished.\n");

    // *** printf randomly stops its output ***
    puts(allAsm);
    free(fileBuf.bytes);
    free(allAsm);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %.3f", cpu_time_used);
    return 0;
}

