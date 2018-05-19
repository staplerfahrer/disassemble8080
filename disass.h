#pragma once

_Bool eof(int idx, int size);

int disassemble8080Op(unsigned char * codeBuffer, int pc);

struct asmLine disassemble8080Line(unsigned char * codeBuffer, int pc);

struct buffer;
char * disassemble8080(struct buffer * pBuffer);
