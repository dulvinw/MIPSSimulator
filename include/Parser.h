#ifndef PARSER_H
#define PARSER_H

#include "AddInstruction.h"
#include "Definitions.h"

#include <string>

using namespace std;

class Parser {

private:
    shared_ptr<Instruction> parseCat1Instruction(const string& line);
    shared_ptr<Instruction> parseCat2Instruction(const string& line);
    shared_ptr<Instruction> parseCat3Instruction(const string& line);
    shared_ptr<Instruction> parseCat4Instruction(const string& line);

public:
    shared_ptr<Instruction> parseLine(const string& line);
    static shared_ptr<InstructionVector> readFile(string& fileName);
    Parser(int instructionId) : _instructionId(instructionId) {}

    Parser() = delete;

private:
    static const int CAT_ONE = 0;
    static const int CAT_TWO = 1;

    // Cat 1 Instructions
    static const int INST_J = 0;
    static const int INST_BEQ = 1;
    static const int INST_BNE = 2;
    static const int INST_BGTZ = 3;
    static const int INST_SW = 4;
    static const int INST_LW = 5;
    static const int INST_BREAK = 6;

    // Cat 2 Instructions
    static const int INST_ADD = 0;
    static const int INST_SUB = 1;
    static const int INST_AND = 2;
    static const int INST_OR = 4;

    // Program counter
    static const int START_INSTRUCTION_ADDRESS = 256;


    int _instructionId;
};

#endif