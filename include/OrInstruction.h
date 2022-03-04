#ifndef OR_INSTRUCTION_H
#define OR_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class OrInstruction: public Instruction {
public:
    void execute();
    std::string decode();
    static std::shared_ptr<OrInstruction> parse(const std::string& line, const int instructionId);
    std::string getInstructionString();

    OrInstruction() = delete;

private:
    OrInstruction(int dest, int srcOne, int srcTwo, const std::string& line, const int instructionId) 
                        : _dest(dest), _srcOne(srcOne), _srcTwo(srcTwo), Instruction(line, instructionId) {}

private:
    int _dest;
    int _srcOne;
    int _srcTwo;
};

#endif