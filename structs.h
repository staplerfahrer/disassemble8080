#pragma once

struct asmLine
{
    // max string length 18 + \0
    char line[19];
    int pc;
};
