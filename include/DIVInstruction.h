#ifndef DIV_INSTRUCTION_H
#define DIV_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class DIVInstruction: public Instruction {
public:
    int execute(int* registers, DataMap& data);
    std::string decode();
    static std::shared_ptr<DIVInstruction> parse(const std::string& line, const int instructionId);
    std::string getInstructionString();

    DIVInstruction() = delete;

private:
    DIVInstruction(int rt, int rs, const std::string& line, const int instructionId) 
                        : _rs(rs), _rt(rt), Instruction(line, instructionId) {}


private:
    int _rs;
    int _rt;
};

#endif