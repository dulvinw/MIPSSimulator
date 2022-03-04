#include "OrIInstruction.h"

#include <iostream>
#include <sstream>

int OrIInstruction::execute(int* registers, DataMap& data) {
    registers[_dest] = registers[_srcOne] | _immediate;
    return _instructionId + NEXT_INSTRUCTION_OFFSET;
}

std::string OrIInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << getInstructionString() << std::endl;

    return ss.str();
}

std::string OrIInstruction::getInstructionString() {
    std::stringstream ss;
    ss << "ORI " << "R" << _dest << ", R" << _srcOne << ", #" << _immediate;

    return ss.str();
}

std::shared_ptr<OrIInstruction> OrIInstruction::parse(const std::string& line, const int instructionId) {
    auto dest = stoi(line.substr(6, 5), 0, 2);
    auto srcOne = stoi(line.substr(11, 5), 0, 2);
    auto immediate = stoi(line.substr(16, 16), 0, 2);

    return std::shared_ptr<OrIInstruction>(new OrIInstruction(dest, srcOne, immediate, line, instructionId));
}