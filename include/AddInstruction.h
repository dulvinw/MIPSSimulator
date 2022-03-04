#ifndef ADD_INSTRUCTION_H
#define ADD_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class AddInstruction: public Instruction {
public:
    int execute(int* registers, DataMap& data);
    std::string decode();
    static AddInstruction* parse(const std::string& line, const int instructionId);
    std::string getInstructionString();

    AddInstruction() = delete;

private:
    AddInstruction(int dest, int srcOne, int srcTwo, const std::string& line, const int instructionId) 
                        : _dest(dest), _srcOne(srcOne), _srcTwo(srcTwo), Instruction(line, instructionId) {}

private:
    int _dest;
    int _srcOne;
    int _srcTwo;
};

#endif