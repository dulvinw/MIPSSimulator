#ifndef SRA_INSTRUCTION_H
#define SRA_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class SRAInstruction: public Instruction {
public:
    int execute(int* registers, DataMap& data);
    std::string decode();
    static std::shared_ptr<SRAInstruction> parse(const std::string& line, const int instructionId);
    std::string getInstructionString();

    SRAInstruction() = delete;

private:
    SRAInstruction(int dest, int srcOne, int immediate, const std::string& line, const int instructionId) 
                        : _dest(dest), _srcOne(srcOne), _immediate(immediate), Instruction(line, instructionId) {}

private:
    int _dest;
    int _srcOne;
    int _immediate;
};

#endif