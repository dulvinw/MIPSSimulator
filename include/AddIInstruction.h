#ifndef ADDI_INSTRUCTION_H
#define ADDI_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class AddIInstruction: public Instruction {
public:
    int execute(int* registers, DataMap& data);
    std::string decode();
    static AddIInstruction* parse(const std::string& line, const int instructionId);
    std::string getInstructionString();

    AddIInstruction() = delete;

private:
    AddIInstruction(int dest, int srcOne, int immediate, const std::string& line, const int instructionId) 
                        : _dest(dest), _srcOne(srcOne), _immediate(immediate), Instruction(line, instructionId) {}

private:
    int _dest;
    int _srcOne;
    int _immediate;
};

#endif