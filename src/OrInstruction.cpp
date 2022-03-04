#include "OrInstruction.h"

#include <iostream>
#include <sstream>

int OrInstruction::execute(int* registers, DataMap& data) {
    registers[_dest] = registers[_srcOne] | registers[_srcTwo];
    return _instructionId + NEXT_INSTRUCTION_OFFSET;
}

std::string OrInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << getInstructionString() << std::endl;

    return ss.str();
}

std::string OrInstruction::getInstructionString() {
    std::stringstream ss;
    ss << "OR " << "R" << _dest << ", R" << _srcOne << ", R" << _srcTwo;

    return ss.str();
}

OrInstruction* OrInstruction::parse(const std::string& line, const int instructionId) {
    auto dest = stoi(line.substr(6, 5), 0, 2);
    auto srcOne = stoi(line.substr(11, 5), 0, 2);
    auto srcTwo = stoi(line.substr(16, 5), 0, 2);

    return new OrInstruction(dest, srcOne, srcTwo, line, instructionId);
}
