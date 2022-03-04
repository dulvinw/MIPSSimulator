#ifndef SRL_INSTRUCTION_H
#define SRL_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class SRLInstruction: public Instruction {
public:
    void execute();
    std::string decode();
    static std::shared_ptr<SRLInstruction> parse(const std::string& line, const int instructionId);

    SRLInstruction() = delete;

private:
    SRLInstruction(int dest, int srcOne, int immediate, const std::string& line, const int instructionId) 
                        : _dest(dest), _srcOne(srcOne), _immediate(immediate), Instruction(line, instructionId) {}

private:
    int _dest;
    int _srcOne;
    int _immediate;
};

#endif