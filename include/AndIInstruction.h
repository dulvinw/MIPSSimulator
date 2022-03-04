#ifndef ANDI_INSTRUCTION_H
#define ANDI_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class AndIInstruction: public Instruction {
public:
    void execute();
    std::string decode();
    static std::shared_ptr<AndIInstruction> parse(const std::string& line, const int instructionId);

    AndIInstruction() = delete;

private:
    AndIInstruction(int dest, int srcOne, int immediate, const std::string& line, const int instructionId) 
                        : _dest(dest), _srcOne(srcOne), _immediate(immediate), Instruction(line, instructionId) {}

private:
    int _dest;
    int _srcOne;
    int _immediate;
};

#endif