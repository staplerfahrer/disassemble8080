#pragma once

struct asmLine
{
    char line[80];
    int pc;
};

struct buffer
{
    unsigned char *bytes;
    int length;
};
