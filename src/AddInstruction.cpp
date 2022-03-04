#include "AddInstruction.h"

#include <iostream>
#include <sstream>

int AddInstruction::execute(int* registers, DataMap& data) {
    registers[_dest] = registers[_srcOne] + registers[_srcTwo];
    return _instructionId + NEXT_INSTRUCTION_OFFSET;
}

std::string AddInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() <<  getInstructionString() << std::endl;

    return ss.str();
}

std::string AddInstruction::getInstructionString() {
    std::stringstream ss;
    ss << "ADD " << "R" << _dest << ", R" << _srcOne << ", R" << _srcTwo;

    return ss.str();
}

std::shared_ptr<AddInstruction> AddInstruction::parse(const std::string& line, const int instructionId) {
    auto dest = stoi(line.substr(6, 5), 0, 2);
    auto srcOne = stoi(line.substr(11, 5), 0, 2);
    auto srcTwo = stoi(line.substr(16, 5), 0, 2);

    return std::shared_ptr<AddInstruction>(new AddInstruction(dest, srcOne, srcTwo, line, instructionId));
}
