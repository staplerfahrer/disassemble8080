#pragma once

_Bool eof(int bufferSize, int ptr);

int disassemble8080Op(unsigned char * codeBuffer, int pc);

struct asmLine disassemble8080Char(unsigned char * codeBuffer, int pc);

int disassemble8080(unsigned char * disassembled, unsigned char * romBytes, int bufferSize);
