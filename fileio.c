#include <stdio.h>
#include <stdlib.h>

int fileToBuffer(const char * filename, unsigned char * buffer)
{
    //FILE * f = fopen(argv[1], "rb");
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
    buffer = (unsigned char *)malloc(fsize);

    fread(buffer, fsize, 1, f);
    fclose(f);

	return fsize;
}