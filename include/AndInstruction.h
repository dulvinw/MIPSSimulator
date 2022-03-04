#ifndef AND_INSTRUCTION_H
#define AND_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class AndInstruction: public Instruction {
public:
    int execute(int* registers, DataMap& data);
    std::string decode();
    static AndInstruction* parse(const std::string& line, const int instructionId);
    std::string getInstructionString();

    AndInstruction() = delete;

private:
    AndInstruction(int dest, int srcOne, int srcTwo, const std::string& line, const int instructionId) 
                        : _dest(dest), _srcOne(srcOne), _srcTwo(srcTwo), Instruction(line, instructionId) {}

private:
    int _dest;
    int _srcOne;
    int _srcTwo;
};

#endif