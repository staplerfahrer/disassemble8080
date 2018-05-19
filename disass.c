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

int disassemble8080Op(unsigned char * codeBuffer, int pc)
{
	// up to 18 bytes per line:
	// LXI    SP,#$ffff\n
	unsigned char * code = &codeBuffer[pc];
	int opbytes = 1;
	printf("%04x ", pc);
	switch (*code)
	{
		case 0x00: printf("NOP"); break;
		case 0x01: printf("LXI    B,#$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0x02: printf("STAX   B"); break;
		case 0x03: printf("INX    B"); break;
		case 0x04: printf("INR    B"); break;
		case 0x05: printf("DCR    B"); break;
		case 0x06: printf("MVI    B,#$%02x", code[1]); opbytes=2; break;
		case 0x07: printf("RLC"); break;
		case 0x08: printf("-"); break;
		case 0x09: printf("DAD    B"); break;
		case 0x0a: printf("LDAX   B"); break;
		case 0x0b: printf("DCX    B"); break;
		case 0x0c: printf("INR    C"); break;
		case 0x0d: printf("DCR    C"); break;
		case 0x0e: printf("MVI    C,#$%02x", code[1]); opbytes=2; break;
		case 0x0f: printf("RRC"); break;
		case 0x10: printf("-"); break;
		case 0x11: printf("LXI    D,#$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0x12: printf("STAX   D"); break;
		case 0x13: printf("INX    D"); break;
		case 0x14: printf("INR    D"); break;
		case 0x15: printf("DCR    D"); break;
		case 0x16: printf("MVI    D,#$%02x", code[1]); opbytes=2; break;
		case 0x17: printf("RAL"); break;
		case 0x18: printf("-"); break;
		case 0x19: printf("DAD    D"); break;
		case 0x1a: printf("LDAX   D"); break;
		case 0x1b: printf("DCX    D"); break;
		case 0x1c: printf("INR    E"); break;
		case 0x1d: printf("DCR    E"); break;
		case 0x1e: printf("MVI    E,#$%02x", code[1]); opbytes=2; break;
		case 0x1f: printf("RAR"); break;
		case 0x20: printf("RIM"); break;
		case 0x21: printf("LXI    H,#$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0x22: printf("SHLD   #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0x23: printf("INX    H"); break;
		case 0x24: printf("INR    H"); break;
		case 0x25: printf("DCR    H"); break;
		case 0x26: printf("MVI    H,#$%02x", code[1]); opbytes=2; break;
		case 0x27: printf("DAA"); break;
		case 0x28: printf("-"); break;
		case 0x29: printf("DAD    H"); break;
		case 0x2a: printf("LHLD   #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0x2b: printf("DCX    H"); break;
		case 0x2c: printf("INR    L"); break;
		case 0x2d: printf("DCR    L"); break;
		case 0x2e: printf("MVI    L,#$%02x", code[1]); opbytes=2; break;
		case 0x2f: printf("CMA"); break;
		case 0x30: printf("SIM"); break;
		case 0x31: printf("LXI    SP,#$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0x32: printf("STA    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0x33: printf("INX    SP"); break;
		case 0x34: printf("INR    M"); break;
		case 0x35: printf("DCR    M"); break;
		case 0x36: printf("MVI    M,#$%02x", code[1]); opbytes=2; break;
		case 0x37: printf("STC"); break;
		case 0x38: printf("-"); break;
		case 0x39: printf("DAD    SP"); break;
		case 0x3a: printf("LDA    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0x3b: printf("DCX    SP"); break;
		case 0x3c: printf("INR    A"); break;
		case 0x3d: printf("DCR    A"); break;
		case 0x3e: printf("MVI    A,#$%02x", code[1]); opbytes=2; break;
		case 0x3f: printf("CMC"); break;
		case 0x40: printf("MOV    B,B"); break;
		case 0x41: printf("MOV    B,C"); break;
		case 0x42: printf("MOV    B,D"); break;
		case 0x43: printf("MOV    B,E"); break;
		case 0x44: printf("MOV    B,H"); break;
		case 0x45: printf("MOV    B,L"); break;
		case 0x46: printf("MOV    B,M"); break;
		case 0x47: printf("MOV    B,A"); break;
		case 0x48: printf("MOV    C,B"); break;
		case 0x49: printf("MOV    C,C"); break;
		case 0x4a: printf("MOV    C,D"); break;
		case 0x4b: printf("MOV    C,E"); break;
		case 0x4c: printf("MOV    C,H"); break;
		case 0x4d: printf("MOV    C,L"); break;
		case 0x4e: printf("MOV    C,M"); break;
		case 0x4f: printf("MOV    C,A"); break;
		case 0x50: printf("MOV    D,B"); break;
		case 0x51: printf("MOV    D,C"); break;
		case 0x52: printf("MOV    D,D"); break;
		case 0x53: printf("MOV    D,E"); break;
		case 0x54: printf("MOV    D,H"); break;
		case 0x55: printf("MOV    D,L"); break;
		case 0x56: printf("MOV    D,M"); break;
		case 0x57: printf("MOV    D,A"); break;
		case 0x58: printf("MOV    E,B"); break;
		case 0x59: printf("MOV    E,C"); break;
		case 0x5a: printf("MOV    E,D"); break;
		case 0x5b: printf("MOV    E,E"); break;
		case 0x5c: printf("MOV    E,H"); break;
		case 0x5d: printf("MOV    E,L"); break;
		case 0x5e: printf("MOV    E,M"); break;
		case 0x5f: printf("MOV    E,A"); break;
		case 0x60: printf("MOV    H,B"); break;
		case 0x61: printf("MOV    H,C"); break;
		case 0x62: printf("MOV    H,D"); break;
		case 0x63: printf("MOV    H,E"); break;
		case 0x64: printf("MOV    H,H"); break;
		case 0x65: printf("MOV    H,L"); break;
		case 0x66: printf("MOV    H,M"); break;
		case 0x67: printf("MOV    H,A"); break;
		case 0x68: printf("MOV    L,B"); break;
		case 0x69: printf("MOV    L,C"); break;
		case 0x6a: printf("MOV    L,D"); break;
		case 0x6b: printf("MOV    L,E"); break;
		case 0x6c: printf("MOV    L,H"); break;
		case 0x6d: printf("MOV    L,L"); break;
		case 0x6e: printf("MOV    L,M"); break;
		case 0x6f: printf("MOV    L,A"); break;
		case 0x70: printf("MOV    M,B"); break;
		case 0x71: printf("MOV    M,C"); break;
		case 0x72: printf("MOV    M,D"); break;
		case 0x73: printf("MOV    M,E"); break;
		case 0x74: printf("MOV    M,H"); break;
		case 0x75: printf("MOV    M,L"); break;
		case 0x76: printf("HLT"); break;
		case 0x77: printf("MOV    M,A"); break;
		case 0x78: printf("MOV    A,B"); break;
		case 0x79: printf("MOV    A,C"); break;
		case 0x7a: printf("MOV    A,D"); break;
		case 0x7b: printf("MOV    A,E"); break;
		case 0x7c: printf("MOV    A,H"); break;
		case 0x7d: printf("MOV    A,L"); break;
		case 0x7e: printf("MOV    A,M"); break;
		case 0x7f: printf("MOV    A,A"); break;
		case 0x80: printf("ADD    B"); break;
		case 0x81: printf("ADD    C"); break;
		case 0x82: printf("ADD    D"); break;
		case 0x83: printf("ADD    E"); break;
		case 0x84: printf("ADD    H"); break;
		case 0x85: printf("ADD    L"); break;
		case 0x86: printf("ADD    M"); break;
		case 0x87: printf("ADD    A"); break;
		case 0x88: printf("ADC    B"); break;
		case 0x89: printf("ADC    C"); break;
		case 0x8a: printf("ADC    D"); break;
		case 0x8b: printf("ADC    E"); break;
		case 0x8c: printf("ADC    H"); break;
		case 0x8d: printf("ADC    L"); break;
		case 0x8e: printf("ADC    M"); break;
		case 0x8f: printf("ADC    A"); break;
		case 0x90: printf("SUB    B"); break;
		case 0x91: printf("SUB    C"); break;
		case 0x92: printf("SUB    D"); break;
		case 0x93: printf("SUB    E"); break;
		case 0x94: printf("SUB    H"); break;
		case 0x95: printf("SUB    L"); break;
		case 0x96: printf("SUB    M"); break;
		case 0x97: printf("SUB    A"); break;
		case 0x98: printf("SBB    B"); break;
		case 0x99: printf("SBB    C"); break;
		case 0x9a: printf("SBB    D"); break;
		case 0x9b: printf("SBB    E"); break;
		case 0x9c: printf("SBB    H"); break;
		case 0x9d: printf("SBB    L"); break;
		case 0x9e: printf("SBB    M"); break;
		case 0x9f: printf("SBB    A"); break;
		case 0xa0: printf("ANA    B"); break;
		case 0xa1: printf("ANA    C"); break;
		case 0xa2: printf("ANA    D"); break;
		case 0xa3: printf("ANA    E"); break;
		case 0xa4: printf("ANA    H"); break;
		case 0xa5: printf("ANA    L"); break;
		case 0xa6: printf("ANA    M"); break;
		case 0xa7: printf("ANA    A"); break;
		case 0xa8: printf("XRA    B"); break;
		case 0xa9: printf("XRA    C"); break;
		case 0xaa: printf("XRA    D"); break;
		case 0xab: printf("XRA    E"); break;
		case 0xac: printf("XRA    H"); break;
		case 0xad: printf("XRA    L"); break;
		case 0xae: printf("XRA    M"); break;
		case 0xaf: printf("XRA    A"); break;
		case 0xb0: printf("ORA    B"); break;
		case 0xb1: printf("ORA    C"); break;
		case 0xb2: printf("ORA    D"); break;
		case 0xb3: printf("ORA    E"); break;
		case 0xb4: printf("ORA    H"); break;
		case 0xb5: printf("ORA    L"); break;
		case 0xb6: printf("ORA    M"); break;
		case 0xb7: printf("ORA    A"); break;
		case 0xb8: printf("CMP    B"); break;
		case 0xb9: printf("CMP    C"); break;
		case 0xba: printf("CMP    D"); break;
		case 0xbb: printf("CMP    E"); break;
		case 0xbc: printf("CMP    H"); break;
		case 0xbd: printf("CMP    L"); break;
		case 0xbe: printf("CMP    M"); break;
		case 0xbf: printf("CMP    A"); break;
		case 0xc0: printf("RNZ"); break;
		case 0xc1: printf("POP    B"); break;
		case 0xc2: printf("JNZ    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xc3: printf("JMP    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xc4: printf("CNZ    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xc5: printf("PUSH   B"); break;
		case 0xc6: printf("ADI    #$%02x", code[1]); opbytes=2; break;
		case 0xc7: printf("RST    0"); break;
		case 0xc8: printf("RZ"); break;
		case 0xc9: printf("RET"); break;
		case 0xca: printf("JZ     #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xcb: printf("-"); break;
		case 0xcc: printf("CZ     #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xcd: printf("CALL   #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xce: printf("ADI    #$%02x", code[1]); opbytes=2; break;
		case 0xcf: printf("RST    1"); break;
		case 0xd0: printf("RNC"); break;
		case 0xd1: printf("POP    D"); break;
		case 0xd2: printf("JNC    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xd3: printf("OUT    #$%02x", code[1]); opbytes=2; break;
		case 0xd4: printf("CNC    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xd5: printf("PUSH   D"); break;
		case 0xd6: printf("SUI    #$%02x", code[1]); opbytes=2; break;
		case 0xd7: printf("RST    2"); break;
		case 0xd8: printf("RC"); break;
		case 0xd9: printf("-"); break;
		case 0xda: printf("JC     #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xdb: printf("IN     #$%02x", code[1]); opbytes=2; break;
		case 0xdc: printf("CC     #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xdd: printf("-"); break;
		case 0xde: printf("SBI    #$%02x", code[1]); opbytes=2; break;
		case 0xdf: printf("RST    3"); break;
		case 0xe0: printf("RPO"); break;
		case 0xe1: printf("POP    H"); break;
		case 0xe2: printf("JPO    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xe3: printf("XTHL"); break;
		case 0xe4: printf("CPO    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xe5: printf("PUSH   H"); break;
		case 0xe6: printf("ANI    #$%02x", code[1]); opbytes=2; break;
		case 0xe7: printf("RST    4"); break;
		case 0xe8: printf("RPE"); break;
		case 0xe9: printf("PCHL"); break;
		case 0xea: printf("JPE    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xeb: printf("XCHG"); break;
		case 0xec: printf("CPE    #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xed: printf("-"); break;
		case 0xee: printf("XRI    #$%02x", code[1]); opbytes=2; break;
		case 0xef: printf("RST    5"); break;
		case 0xf0: printf("RP"); break;
		case 0xf1: printf("POP PSW"); break;
		case 0xf2: printf("JP     #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xf3: printf("DI"); break;
		case 0xf4: printf("CP     #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xf5: printf("PUSH PSW"); break;
		case 0xf6: printf("ORI    #$%02x", code[1]); opbytes=2; break;
		case 0xf7: printf("RST    6"); break;
		case 0xf8: printf("RM"); break;
		case 0xf9: printf("SPHL"); break;
		case 0xfa: printf("JM     #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xfb: printf("EI"); break;
		case 0xfc: printf("CM     #$%02x%02x", code[2], code[1]); opbytes=2; break;
		case 0xfd: printf("-"); break;
		case 0xfe: printf("CPI    #$%02x", code[1]); opbytes=2; break;
		case 0xff: printf("RST    7"); break;
	}
	//printf("\t\tsize %u", opbytes);

	printf("\n");

	return opbytes;
}

struct asmLine disassemble8080Line(unsigned char * codeBuffer, int pc)
{
	// up to 18 bytes per line:
	// LXI    SP,#$ffff\n
	// With \0:
	char instr[asmLineLength()];
	unsigned char * code = &codeBuffer[pc];
	//printf("pc:\t0x%04x,\topcode:\t0x%02x\n", pc, *code);
	//printf("before nop");
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
		case 0x08: sprintf(instr, "-"); break;
		case 0x09: sprintf(instr, "DAD    B"); break;
		case 0x0a: sprintf(instr, "LDAX   B"); break;
		case 0x0b: sprintf(instr, "DCX    B"); break;
		case 0x0c: sprintf(instr, "INR    C"); break;
		case 0x0d: sprintf(instr, "DCR    C"); break;
		case 0x0e: sprintf(instr, "MVI    C,#$%02x", code[1]); opbytes=2; break;
		case 0x0f: sprintf(instr, "RRC"); break;
		case 0x10: sprintf(instr, "-"); break;
		case 0x11: sprintf(instr, "LXI    D,#$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0x12: sprintf(instr, "STAX   D"); break;
		case 0x13: sprintf(instr, "INX    D"); break;
		case 0x14: sprintf(instr, "INR    D"); break;
		case 0x15: sprintf(instr, "DCR    D"); break;
		case 0x16: sprintf(instr, "MVI    D,#$%02x", code[1]); opbytes=2; break;
		case 0x17: sprintf(instr, "RAL"); break;
		case 0x18: sprintf(instr, "-"); break;
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
		case 0x28: sprintf(instr, "-"); break;
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
		case 0x38: sprintf(instr, "-"); break;
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
		case 0xcb: sprintf(instr, "-"); break;
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
		case 0xd9: sprintf(instr, "-"); break;
		case 0xda: sprintf(instr, "JC     #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xdb: sprintf(instr, "IN     #$%02x", code[1]); opbytes=2; break;
		case 0xdc: sprintf(instr, "CC     #$%02x%02x", code[2], code[1]); opbytes=3; break;
		case 0xdd: sprintf(instr, "-"); break;
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
		case 0xed: sprintf(instr, "-"); break;
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
		case 0xfd: sprintf(instr, "-"); break;
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
		printf(line.line);
		strcat(allAsmLines, line.line);
		strcat(allAsmLines, "\n");
		pc = line.pc;
	} 

	return allAsmLines;
}
