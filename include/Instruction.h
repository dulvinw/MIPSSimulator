#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <sstream>
class Instruction {
public:
    virtual void execute() = 0;
    virtual std::string decode() = 0;

    std::string getPreamble() {
        std::stringstream ss;
        ss << _line << "\t" << _instructionId << "\t\t";

        return ss.str();
    }

    Instruction(const std::string& line, const int instructionId) : _line(line), _instructionId(instructionId) {}
    virtual ~Instruction() {}

    Instruction() = delete;

protected:
    const std::string _line;
    int _instructionId;
};

#endif