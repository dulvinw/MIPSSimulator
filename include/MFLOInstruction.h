#ifndef MFLO_INSTRUCTION_H
#define MFLO_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class MFLOInstruction: public Instruction {
public:
    int execute(int* registers, DataMap& data);
    std::string decode();
    static std::shared_ptr<MFLOInstruction> parse(const std::string& line, const int instructionId);
    std::string getInstructionString();

    MFLOInstruction() = delete;

private:
    MFLOInstruction(int rs, const std::string& line, const int instructionId) 
                        : _dest(rs), Instruction(line, instructionId) {}


private:
    int _dest;
};

#endif