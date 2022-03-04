#ifndef JUMP_INSTRUCTION_H
#define JUMP_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class JumpInstruction : public Instruction {
public:
    int execute(int* registers, DataMap& data);
    std::string decode();

    static std::shared_ptr<JumpInstruction> parse(const std::string& line, const int instructionId);
    std::string getInstructionString();

private:
    JumpInstruction(int jumpTo, const std::string& line, const int instructionId) 
                        : _jumpTo(jumpTo), Instruction(line, instructionId) {}

private:

    int _jumpTo;
};

#endif