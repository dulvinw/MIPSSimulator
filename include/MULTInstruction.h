#ifndef MULT_INSTRUCTION_H
#define MULT_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class MULTInstruction: public Instruction {
public:
    int execute(int* registers, DataMap& data);
    std::string decode();
    static std::shared_ptr<MULTInstruction> parse(const std::string& line, const int instructionId);
    std::string getInstructionString();

    MULTInstruction() = delete;

private:
    MULTInstruction(int rt, int rs, const std::string& line, const int instructionId) 
                        : _rs(rs), _rt(rt), Instruction(line, instructionId) {}


private:
    int _rs;
    int _rt;
};

#endif