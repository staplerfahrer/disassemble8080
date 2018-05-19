#include "disass.h"
#include "structs.h"

void instructionList()
{
    unsigned char buffer[256];
    unsigned long long i;
    for (i = 0; i < sizeof(buffer); i++)
    {
        buffer[i] = i;
    }
    
    for (i = 0; i < sizeof(buffer); i++)
    {
        disassemble8080Op(buffer, i);
    }
}