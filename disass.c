#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "structs.h"

_Bool eof(int idx, int size)
{
	return idx >= size;
}

int asmLineLength()
{
	// address + instruction + registers + bytes + newline
	int l = 5 + 7 + 3 + 6 + 2;
	return l;
}

// char * fmt(char *line, char *codeFormat, int pc, char *code)
// {
// 	// how should I include the optional extra bytes? 
// 	char lineFormat[80];
// 	// reset the string to 0 length
// 	lineFormat[0] = '\0';

// 	// ffff_  for the program counter
// 	strcat(lineFormat, "%04x ");

// 	// plus whatever particular code formatting
// 	strcat(lineFormat, codeFormat);

// 	sprintf(line, lineFormat, pc, code);
// 	return line;
// }

struct asmLine disassemble8080Line(unsigned char * codeBuffer, int pc)
{
	unsigned char * code = &codeBuffer[pc];
	char instr[asmLineLength()];
	int opbytes = 1;
	switch (*code)
	{
		case 0x00: sprintf(instr, "NOP"); break;
		case 0x01: sprintf(instr, "LXI    B,#$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0x02: sprintf(instr, "STAX   B"); break;
		case 0x03: sprintf(instr, "INX    B"); break;
		case 0x04: sprintf(instr, "INR    B"); break;
		case 0x05: sprintf(instr, "DCR    B"); break;
		case 0x06: sprintf(instr, "MVI    B,#$%02x", code[1]); opbytes=2; break;
		case 0x07: sprintf(instr, "RLC"); break;
		case 0x08: sprintf(instr, "(0x%02x)", code[0]); break;
		case 0x09: sprintf(instr, "DAD    B"); break;
		case 0x0a: sprintf(instr, "LDAX   B"); break;
		case 0x0b: sprintf(instr, "DCX    B"); break;
		case 0x0c: sprintf(instr, "INR    C"); break;
		case 0x0d: sprintf(instr, "DCR    C"); break;
		case 0x0e: sprintf(instr, "MVI    C,#$%02x", code[1]); opbytes=2; break;
		case 0x0f: sprintf(instr, "RRC"); break;
		case 0x10: sprintf(instr, "(0x%02x)", code[0]); break;
		case 0x11: sprintf(instr, "LXI    D,#$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0x12: sprintf(instr, "STAX   D"); break;
		case 0x13: sprintf(instr, "INX    D"); break;
		case 0x14: sprintf(instr, "INR    D"); break;
		case 0x15: sprintf(instr, "DCR    D"); break;
		case 0x16: sprintf(instr, "MVI    D,#$%02x", code[1]); opbytes=2; break;
		case 0x17: sprintf(instr, "RAL"); break;
		case 0x18: sprintf(instr, "(0x%02x)", code[0]); break;
		case 0x19: sprintf(instr, "DAD    D"); break;
		case 0x1a: sprintf(instr, "LDAX   D"); break;
		case 0x1b: sprintf(instr, "DCX    D"); break;
		case 0x1c: sprintf(instr, "INR    E"); break;
		case 0x1d: sprintf(instr, "DCR    E"); break;
		case 0x1e: sprintf(instr, "MVI    E,#$%02x", code[1]); opbytes=2; break;
		case 0x1f: sprintf(instr, "RAR"); break;
		case 0x20: sprintf(instr, "RIM"); break;
		case 0x21: sprintf(instr, "LXI    H,#$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0x22: sprintf(instr, "SHLD   #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0x23: sprintf(instr, "INX    H"); break;
		case 0x24: sprintf(instr, "INR    H"); break;
		case 0x25: sprintf(instr, "DCR    H"); break;
		case 0x26: sprintf(instr, "MVI    H,#$%02x", code[1]); opbytes=2; break;
		case 0x27: sprintf(instr, "DAA"); break;
		case 0x28: sprintf(instr, "(0x%02x)", code[0]); break;
		case 0x29: sprintf(instr, "DAD    H"); break;
		case 0x2a: sprintf(instr, "LHLD   #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0x2b: sprintf(instr, "DCX    H"); break;
		case 0x2c: sprintf(instr, "INR    L"); break;
		case 0x2d: sprintf(instr, "DCR    L"); break;
		case 0x2e: sprintf(instr, "MVI    L,#$%02x", code[1]); opbytes=2; break;
		case 0x2f: sprintf(instr, "CMA"); break;
		case 0x30: sprintf(instr, "SIM"); break;
		case 0x31: sprintf(instr, "LXI    SP,#$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0x32: sprintf(instr, "STA    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0x33: sprintf(instr, "INX    SP"); break;
		case 0x34: sprintf(instr, "INR    M"); break;
		case 0x35: sprintf(instr, "DCR    M"); break;
		case 0x36: sprintf(instr, "MVI    M,#$%02x", code[1]); opbytes=2; break;
		case 0x37: sprintf(instr, "STC"); break;
		case 0x38: sprintf(instr, "(0x%02x)", code[0]); break;
		case 0x39: sprintf(instr, "DAD    SP"); break;
		case 0x3a: sprintf(instr, "LDA    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0x3b: sprintf(instr, "DCX    SP"); break;
		case 0x3c: sprintf(instr, "INR    A"); break;
		case 0x3d: sprintf(instr, "DCR    A"); break;
		case 0x3e: sprintf(instr, "MVI    A,#$%02x", code[1]); opbytes=2; break;
		case 0x3f: sprintf(instr, "CMC"); break;
		case 0x40: sprintf(instr, "MOV    B,B"); break;
		case 0x41: sprintf(instr, "MOV    B,C"); break;
		case 0x42: sprintf(instr, "MOV    B,D"); break;
		case 0x43: sprintf(instr, "MOV    B,E"); break;
		case 0x44: sprintf(instr, "MOV    B,H"); break;
		case 0x45: sprintf(instr, "MOV    B,L"); break;
		case 0x46: sprintf(instr, "MOV    B,M"); break;
		case 0x47: sprintf(instr, "MOV    B,A"); break;
		case 0x48: sprintf(instr, "MOV    C,B"); break;
		case 0x49: sprintf(instr, "MOV    C,C"); break;
		case 0x4a: sprintf(instr, "MOV    C,D"); break;
		case 0x4b: sprintf(instr, "MOV    C,E"); break;
		case 0x4c: sprintf(instr, "MOV    C,H"); break;
		case 0x4d: sprintf(instr, "MOV    C,L"); break;
		case 0x4e: sprintf(instr, "MOV    C,M"); break;
		case 0x4f: sprintf(instr, "MOV    C,A"); break;
		case 0x50: sprintf(instr, "MOV    D,B"); break;
		case 0x51: sprintf(instr, "MOV    D,C"); break;
		case 0x52: sprintf(instr, "MOV    D,D"); break;
		case 0x53: sprintf(instr, "MOV    D,E"); break;
		case 0x54: sprintf(instr, "MOV    D,H"); break;
		case 0x55: sprintf(instr, "MOV    D,L"); break;
		case 0x56: sprintf(instr, "MOV    D,M"); break;
		case 0x57: sprintf(instr, "MOV    D,A"); break;
		case 0x58: sprintf(instr, "MOV    E,B"); break;
		case 0x59: sprintf(instr, "MOV    E,C"); break;
		case 0x5a: sprintf(instr, "MOV    E,D"); break;
		case 0x5b: sprintf(instr, "MOV    E,E"); break;
		case 0x5c: sprintf(instr, "MOV    E,H"); break;
		case 0x5d: sprintf(instr, "MOV    E,L"); break;
		case 0x5e: sprintf(instr, "MOV    E,M"); break;
		case 0x5f: sprintf(instr, "MOV    E,A"); break;
		case 0x60: sprintf(instr, "MOV    H,B"); break;
		case 0x61: sprintf(instr, "MOV    H,C"); break;
		case 0x62: sprintf(instr, "MOV    H,D"); break;
		case 0x63: sprintf(instr, "MOV    H,E"); break;
		case 0x64: sprintf(instr, "MOV    H,H"); break;
		case 0x65: sprintf(instr, "MOV    H,L"); break;
		case 0x66: sprintf(instr, "MOV    H,M"); break;
		case 0x67: sprintf(instr, "MOV    H,A"); break;
		case 0x68: sprintf(instr, "MOV    L,B"); break;
		case 0x69: sprintf(instr, "MOV    L,C"); break;
		case 0x6a: sprintf(instr, "MOV    L,D"); break;
		case 0x6b: sprintf(instr, "MOV    L,E"); break;
		case 0x6c: sprintf(instr, "MOV    L,H"); break;
		case 0x6d: sprintf(instr, "MOV    L,L"); break;
		case 0x6e: sprintf(instr, "MOV    L,M"); break;
		case 0x6f: sprintf(instr, "MOV    L,A"); break;
		case 0x70: sprintf(instr, "MOV    M,B"); break;
		case 0x71: sprintf(instr, "MOV    M,C"); break;
		case 0x72: sprintf(instr, "MOV    M,D"); break;
		case 0x73: sprintf(instr, "MOV    M,E"); break;
		case 0x74: sprintf(instr, "MOV    M,H"); break;
		case 0x75: sprintf(instr, "MOV    M,L"); break;
		case 0x76: sprintf(instr, "HLT"); break;
		case 0x77: sprintf(instr, "MOV    M,A"); break;
		case 0x78: sprintf(instr, "MOV    A,B"); break;
		case 0x79: sprintf(instr, "MOV    A,C"); break;
		case 0x7a: sprintf(instr, "MOV    A,D"); break;
		case 0x7b: sprintf(instr, "MOV    A,E"); break;
		case 0x7c: sprintf(instr, "MOV    A,H"); break;
		case 0x7d: sprintf(instr, "MOV    A,L"); break;
		case 0x7e: sprintf(instr, "MOV    A,M"); break;
		case 0x7f: sprintf(instr, "MOV    A,A"); break;
		case 0x80: sprintf(instr, "ADD    B"); break;
		case 0x81: sprintf(instr, "ADD    C"); break;
		case 0x82: sprintf(instr, "ADD    D"); break;
		case 0x83: sprintf(instr, "ADD    E"); break;
		case 0x84: sprintf(instr, "ADD    H"); break;
		case 0x85: sprintf(instr, "ADD    L"); break;
		case 0x86: sprintf(instr, "ADD    M"); break;
		case 0x87: sprintf(instr, "ADD    A"); break;
		case 0x88: sprintf(instr, "ADC    B"); break;
		case 0x89: sprintf(instr, "ADC    C"); break;
		case 0x8a: sprintf(instr, "ADC    D"); break;
		case 0x8b: sprintf(instr, "ADC    E"); break;
		case 0x8c: sprintf(instr, "ADC    H"); break;
		case 0x8d: sprintf(instr, "ADC    L"); break;
		case 0x8e: sprintf(instr, "ADC    M"); break;
		case 0x8f: sprintf(instr, "ADC    A"); break;
		case 0x90: sprintf(instr, "SUB    B"); break;
		case 0x91: sprintf(instr, "SUB    C"); break;
		case 0x92: sprintf(instr, "SUB    D"); break;
		case 0x93: sprintf(instr, "SUB    E"); break;
		case 0x94: sprintf(instr, "SUB    H"); break;
		case 0x95: sprintf(instr, "SUB    L"); break;
		case 0x96: sprintf(instr, "SUB    M"); break;
		case 0x97: sprintf(instr, "SUB    A"); break;
		case 0x98: sprintf(instr, "SBB    B"); break;
		case 0x99: sprintf(instr, "SBB    C"); break;
		case 0x9a: sprintf(instr, "SBB    D"); break;
		case 0x9b: sprintf(instr, "SBB    E"); break;
		case 0x9c: sprintf(instr, "SBB    H"); break;
		case 0x9d: sprintf(instr, "SBB    L"); break;
		case 0x9e: sprintf(instr, "SBB    M"); break;
		case 0x9f: sprintf(instr, "SBB    A"); break;
		case 0xa0: sprintf(instr, "ANA    B"); break;
		case 0xa1: sprintf(instr, "ANA    C"); break;
		case 0xa2: sprintf(instr, "ANA    D"); break;
		case 0xa3: sprintf(instr, "ANA    E"); break;
		case 0xa4: sprintf(instr, "ANA    H"); break;
		case 0xa5: sprintf(instr, "ANA    L"); break;
		case 0xa6: sprintf(instr, "ANA    M"); break;
		case 0xa7: sprintf(instr, "ANA    A"); break;
		case 0xa8: sprintf(instr, "XRA    B"); break;
		case 0xa9: sprintf(instr, "XRA    C"); break;
		case 0xaa: sprintf(instr, "XRA    D"); break;
		case 0xab: sprintf(instr, "XRA    E"); break;
		case 0xac: sprintf(instr, "XRA    H"); break;
		case 0xad: sprintf(instr, "XRA    L"); break;
		case 0xae: sprintf(instr, "XRA    M"); break;
		case 0xaf: sprintf(instr, "XRA    A"); break;
		case 0xb0: sprintf(instr, "ORA    B"); break;
		case 0xb1: sprintf(instr, "ORA    C"); break;
		case 0xb2: sprintf(instr, "ORA    D"); break;
		case 0xb3: sprintf(instr, "ORA    E"); break;
		case 0xb4: sprintf(instr, "ORA    H"); break;
		case 0xb5: sprintf(instr, "ORA    L"); break;
		case 0xb6: sprintf(instr, "ORA    M"); break;
		case 0xb7: sprintf(instr, "ORA    A"); break;
		case 0xb8: sprintf(instr, "CMP    B"); break;
		case 0xb9: sprintf(instr, "CMP    C"); break;
		case 0xba: sprintf(instr, "CMP    D"); break;
		case 0xbb: sprintf(instr, "CMP    E"); break;
		case 0xbc: sprintf(instr, "CMP    H"); break;
		case 0xbd: sprintf(instr, "CMP    L"); break;
		case 0xbe: sprintf(instr, "CMP    M"); break;
		case 0xbf: sprintf(instr, "CMP    A"); break;
		case 0xc0: sprintf(instr, "RNZ"); break;
		case 0xc1: sprintf(instr, "POP    B"); break;
		case 0xc2: sprintf(instr, "JNZ    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xc3: sprintf(instr, "JMP    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xc4: sprintf(instr, "CNZ    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xc5: sprintf(instr, "PUSH   B"); break;
		case 0xc6: sprintf(instr, "ADI    #$%02x", code[1]); opbytes=2; break;
		case 0xc7: sprintf(instr, "RST    0"); break;
		case 0xc8: sprintf(instr, "RZ"); break;
		case 0xc9: sprintf(instr, "RET"); break;
		case 0xca: sprintf(instr, "JZ     #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xcb: sprintf(instr, "(0x%02x)", code[0]); break;
		case 0xcc: sprintf(instr, "CZ     #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xcd: sprintf(instr, "CALL   #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xce: sprintf(instr, "ADI    #$%02x", code[1]); opbytes=2; break;
		case 0xcf: sprintf(instr, "RST    1"); break;
		case 0xd0: sprintf(instr, "RNC"); break;
		case 0xd1: sprintf(instr, "POP    D"); break;
		case 0xd2: sprintf(instr, "JNC    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xd3: sprintf(instr, "OUT    #$%02x", code[1]); opbytes=2; break;
		case 0xd4: sprintf(instr, "CNC    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xd5: sprintf(instr, "PUSH   D"); break;
		case 0xd6: sprintf(instr, "SUI    #$%02x", code[1]); opbytes=2; break;
		case 0xd7: sprintf(instr, "RST    2"); break;
		case 0xd8: sprintf(instr, "RC"); break;
		case 0xd9: sprintf(instr, "(0x%02x)", code[0]); break;
		case 0xda: sprintf(instr, "JC     #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xdb: sprintf(instr, "IN     #$%02x", code[1]); opbytes=2; break;
		case 0xdc: sprintf(instr, "CC     #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xdd: sprintf(instr, "(0x%02x)", code[0]); break;
		case 0xde: sprintf(instr, "SBI    #$%02x", code[1]); opbytes=2; break;
		case 0xdf: sprintf(instr, "RST    3"); break;
		case 0xe0: sprintf(instr, "RPO"); break;
		case 0xe1: sprintf(instr, "POP    H"); break;
		case 0xe2: sprintf(instr, "JPO    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xe3: sprintf(instr, "XTHL"); break;
		case 0xe4: sprintf(instr, "CPO    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xe5: sprintf(instr, "PUSH   H"); break;
		case 0xe6: sprintf(instr, "ANI    #$%02x", code[1]); opbytes=2; break;
		case 0xe7: sprintf(instr, "RST    4"); break;
		case 0xe8: sprintf(instr, "RPE"); break;
		case 0xe9: sprintf(instr, "PCHL"); break;
		case 0xea: sprintf(instr, "JPE    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xeb: sprintf(instr, "XCHG"); break;
		case 0xec: sprintf(instr, "CPE    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xed: sprintf(instr, "(0x%02x)", code[0]); break;
		case 0xee: sprintf(instr, "XRI    #$%02x", code[1]); opbytes=2; break;
		case 0xef: sprintf(instr, "RST    5"); break;
		case 0xf0: sprintf(instr, "RP"); break;
		case 0xf1: sprintf(instr, "POP PSW"); break;
		case 0xf2: sprintf(instr, "JP     #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xf3: sprintf(instr, "DI"); break;
		case 0xf4: sprintf(instr, "CP     #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xf5: sprintf(instr, "PUSH PSW"); break;
		case 0xf6: sprintf(instr, "ORI    #$%02x", code[1]); opbytes=2; break;
		case 0xf7: sprintf(instr, "RST    6"); break;
		case 0xf8: sprintf(instr, "RM"); break;
		case 0xf9: sprintf(instr, "SPHL"); break;
		case 0xfa: sprintf(instr, "JM     #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xfb: sprintf(instr, "EI"); break;
		case 0xfc: sprintf(instr, "CM     #$%02x%02x", code[2], code[1]); opbytes=2; break;
		case 0xfd: sprintf(instr, "(0x%02x)", code[0]); break;
		case 0xfe: sprintf(instr, "CPI    #$%02x", code[1]); opbytes=2; break;
		case 0xff: sprintf(instr, "RST    7"); break;
	};

	char line[80];
	sprintf(line, "%04x %s", pc, instr);
	struct asmLine al;
	strcpy(al.line, line);
	al.pc = pc + opbytes;
	return al;
}

char * disassemble8080(struct buffer * pBuffer)
{
	struct buffer b = *pBuffer;
	int outStringLength = b.length * asmLineLength();
	char * allAsmLines = malloc(outStringLength);
	allAsmLines[0] = '\0';

	int pc = 0;
	while (!eof(pc, b.length))
	{
		struct asmLine line = disassemble8080Line(b.bytes, pc);
		strcat(allAsmLines, line.line);
		strcat(allAsmLines, "\n");
		pc = line.pc;
	} 

	return allAsmLines;
}
