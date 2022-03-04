#ifndef SUB_INSTRUCTION_H
#define SUB_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class SubInstruction: public Instruction {
public:
    int execute(int* registers, DataMap& data);
    std::string decode();
    static SubInstruction* parse(const std::string& line, const int instructionId);
    std::string getInstructionString();

    SubInstruction() = delete;

private:
    SubInstruction(int dest, int srcOne, int srcTwo, const std::string& line, const int instructionId) 
                        : _dest(dest), _srcOne(srcOne), _srcTwo(srcTwo), Instruction(line, instructionId) {}

private:
    int _dest;
    int _srcOne;
    int _srcTwo;
};

#endif