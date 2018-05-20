#pragma once

_Bool eof(int idx, int size);

struct asmLine disassemble8080Line(unsigned char * codeBuffer, int pc);

// this line is how I can have a struct in the signature:
struct buffer;
char * disassemble8080(struct buffer * pBuffer);
