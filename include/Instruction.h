#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Definitions.h"
#include "Constants.h"

#include <string>
#include <sstream>
class Instruction {
public:
    virtual int execute(int* registers, DataMap& data) = 0;
    virtual std::string decode() = 0;

    std::string getPreamble() {
        std::stringstream ss;
        ss << _line << "\t" << _instructionId << "\t\t";

        return ss.str();
    }

    virtual std::string getInstructionString() = 0;

    int getInstructionId() {return _instructionId;}

    Instruction(const std::string& line, const int instructionId) : _line(line), _instructionId(instructionId) {}
    virtual ~Instruction() {}

    Instruction() = delete;

protected:
    const std::string _line;
    int _instructionId;
};

#endif