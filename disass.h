#pragma once

_Bool eof(int idx, int size);

struct asmLine disassemble8080Line(unsigned char * codeBuffer, int pc);

struct buffer;
char * disassemble8080(struct buffer * pBuffer);
