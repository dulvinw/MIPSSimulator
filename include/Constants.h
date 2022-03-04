#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

static const std::string DISASSEMBLE_FILE_NAME = "disassembly.txt";
static const std::string SIMULATION_FILE_NAME = "simulation.txt";

static const int NUM_OF_REGISTERS = 32;
static const int NUM_OF_COLUMNS_IN_REGISTER_REPORT = 8;

static const int NUM_OF_COLUMNS_IN_DATA_REPORT = 8;

static const int START_INSTRUCTION_ADDRESS = 256;
static const int NEXT_INSTRUCTION_OFFSET = 4;
static const int PROGRAM_EXIT = -1;

#endif