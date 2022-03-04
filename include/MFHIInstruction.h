#ifndef MFHI_INSTRUCTION_H
#define MFHI_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class MFHIInstruction: public Instruction {
public:
    void execute();
    std::string decode();
    static std::shared_ptr<MFHIInstruction> parse(const std::string& line, const int instructionId);
    std::string getInstructionString();

    MFHIInstruction() = delete;

private:
    MFHIInstruction(int rs, const std::string& line, const int instructionId) 
                        : _dest(rs), Instruction(line, instructionId) {}


private:
    int _dest;
};

#endif