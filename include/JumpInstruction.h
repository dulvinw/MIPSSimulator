#ifndef JUMP_INSTRUCTION_H
#define JUMP_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class JumpInstruction : public Instruction {
public:
    void execute();
    std::string decode();

    static std::shared_ptr<JumpInstruction> parse(const std::string& line, const int instructionId);
};

#endif