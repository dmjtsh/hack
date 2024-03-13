#include "stdio.h"

void HackProgram(const char* prog_name)
{
    FILE* prog_file = fopen(prog_name, "wr");

    fseek(prog_file, 190, SEEK_SET);
    fwrite(90 ,sizeof(char),, prog_file);
}