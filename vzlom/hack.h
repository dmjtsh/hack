#pragma once

const char NOP_SYMB = 0x90;

const size_t PLACE_IN_FILE_TO_WRITE = 0x193 - 0x100; // considering org 100h
const size_t SYMBS_TO_WRITE_COUNT   = 31;

void HackProgram(const char* prog_name);