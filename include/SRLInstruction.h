#ifndef SRL_INSTRUCTION_H
#define SRL_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class SRLInstruction: public Instruction {
public:
    int execute(int* registers, DataMap& data);
    std::string decode();
    static SRLInstruction* parse(const std::string& line, const int instructionId);
    std::string getInstructionString();

    SRLInstruction() = delete;

private:
    SRLInstruction(int dest, int srcOne, int immediate, const std::string& line, const int instructionId) 
                        : _dest(dest), _srcOne(srcOne), _immediate(immediate), Instruction(line, instructionId) {}

private:
    int _dest;
    int _srcOne;
    int _immediate;
};

#endif