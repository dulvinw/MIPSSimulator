#ifndef BGTZ_INSTRUCTION_H
#define BGTZ_INSTRUCTION_H

#include "Instruction.h"

#include <string>

class BGTZInstruction: public Instruction {
public:
    void execute();
    std::string decode();
    static std::shared_ptr<BGTZInstruction> parse(const std::string& line, const int instructionId);

    BGTZInstruction() = delete;

private:
    BGTZInstruction(int r, int offset, const std::string& line, const int instructionId) 
                        : _r(r), _offset(offset), Instruction(line, instructionId) {}

    static int getOffset(const std::string& line);

private:
    int _r;
    int _offset;
};

#endif