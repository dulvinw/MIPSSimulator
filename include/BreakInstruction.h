#ifndef BREAK_INSTRUCTION_H
#define BREAK_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class BreakInstruction: public Instruction {
public:
    void execute();
    std::string decode();
    static std::shared_ptr<BreakInstruction> parse(const std::string& line, const int instructionId);
    std::string getInstructionString();

    BreakInstruction() = delete;

private:
    BreakInstruction(int code, const std::string& line, const int instructionId) 
                        : _code(code), Instruction(line, instructionId) {}


private:
    int _code;
};

#endif