#ifndef BNE_INSTRUCTION_H
#define BNE_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class BNEInstruction: public Instruction {
public:
    void execute();
    std::string decode();
    static std::shared_ptr<BNEInstruction> parse(const std::string& line, const int instructionId);

    BNEInstruction() = delete;

private:
    BNEInstruction(int dest, int srcOne, int srcTwo, const std::string& line, const int instructionId) 
                        : _r(dest), _t(srcOne), _offset(srcTwo), Instruction(line, instructionId) {}

    static int getOffset(const std::string& line);

private:
    int _r;
    int _t;
    int _offset;
};

#endif