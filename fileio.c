#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

struct buffer fileToBuffer(const char * filename)
{
    FILE * f = fopen(filename, "rb");
    
	if (f == NULL)
    {
        printf("error: couldn't open %s\n", filename);
        exit(1);
    }

    // get the file size and read it into a memory buffer
    fseek(f, 0L, SEEK_END);
    int fsize = ftell(f);
    fseek(f, 0L, SEEK_SET);

    struct buffer fileBuf;
    fileBuf.bytes = (unsigned char *)malloc(fsize);
    fileBuf.length = fsize;
    fread(fileBuf.bytes, fsize, 1, f);
    fclose(f);

	return fileBuf;
}