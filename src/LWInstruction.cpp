#include "LWInstruction.h"
#include "Data.h"

#include <iostream>
#include <sstream>

int LWInstruction::execute(int* registers, DataMap& data) {
    int memAddress = registers[_base] + _offset;
    registers[_rt] = data[memAddress]->_data;
    return _instructionId + NEXT_INSTRUCTION_OFFSET;
}

std::string LWInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << getInstructionString() << std::endl;

    return ss.str();
}

std::string LWInstruction::getInstructionString() {
    std::stringstream ss;
    ss << "LW R" << _rt << ", " << _offset << "(R" << _base << ")";

    return ss.str();
}

LWInstruction* LWInstruction::parse(const std::string& line, const int instructionId) {
    auto r = stoi(line.substr(6, 5), 0, 2);
    auto t = stoi(line.substr(11, 5), 0, 2);
    auto offset = stoi(line.substr(16, 16), 0, 2);

    return new LWInstruction(r, t, offset, line, instructionId);
}