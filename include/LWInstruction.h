#ifndef LW_INSTRUCTION_H
#define LW_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class LWInstruction: public Instruction {
public:
    int execute(int* registers, DataMap& data);
    std::string decode();
    static std::shared_ptr<LWInstruction> parse(const std::string& line, const int instructionId);
    std::string getInstructionString();

    LWInstruction() = delete;

private:
    LWInstruction(int base, int rt, int offset, const std::string& line, const int instructionId) 
                        : _base(base), _rt(rt), _offset(offset), Instruction(line, instructionId) {}


private:
    int _base;
    int _rt;
    int _offset;
};

#endif