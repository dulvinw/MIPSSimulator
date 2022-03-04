#ifndef BEQ_INSTRUCTION_H
#define BEQ_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class BEQInstruction: public Instruction {
public:
    int execute(int* registers, DataMap& data);
    std::string decode();
    static BEQInstruction* parse(const std::string& line, const int instructionId);
    std::string getInstructionString();

    BEQInstruction() = delete;

private:
    BEQInstruction(int dest, int srcOne, int srcTwo, const std::string& line, const int instructionId) 
                        : _r(dest), _t(srcOne), _offset(srcTwo), Instruction(line, instructionId) {}

    static int getOffset(const std::string& line);

private:
    int _r;
    int _t;
    int _offset;
};

#endif