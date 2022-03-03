#ifndef JUMP_INSTRUCTION_H
#define JUMP_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class JumpInstruction : public Instruction {
public:
    void execute();
    void print();

    static std::shared_ptr<JumpInstruction> parse(const std::string& line);
};

#endif