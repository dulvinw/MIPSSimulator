#ifndef BEQ_INSTRUCTION_H
#define BEQ_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class BEQInstruction: public Instruction {
public:
    void execute();
    std::string decode();
    static std::shared_ptr<BEQInstruction> parse(const std::string& line, const int instructionId);

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