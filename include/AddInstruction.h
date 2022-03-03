#ifndef ADD_INSTRUCTION_H
#define ADD_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class AddInstruction: public Instruction {
public:
    void execute();
    void print();
    static std::shared_ptr<AddInstruction> parse(const std::string& line);

    AddInstruction() = delete;

private:
    AddInstruction(int dest, int srcOne, int srcTwo) : _dest(dest), _srcOne(srcOne), _srcTwo(srcTwo) {}

private:
    int _dest;
    int _srcOne;
    int _srcTwo;
};

#endif