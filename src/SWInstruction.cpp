#include "SWInstruction.h"

#include <iostream>
#include <sstream>

void SWInstruction::execute() {
    std::cout << "Hello world";
}

std::string SWInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << getInstructionString() << std::endl;

    return ss.str();
}

std::string SWInstruction::getInstructionString() {
    std::stringstream ss;
    ss << "SW R" << _rt << ", " << _offset << "(R" << _base << ")";

    return ss.str();
}

std::shared_ptr<SWInstruction> SWInstruction::parse(const std::string& line, const int instructionId) {
    auto r = stoi(line.substr(6, 5), 0, 2);
    auto t = stoi(line.substr(11, 5), 0, 2);
    auto offset = stoi(line.substr(16, 16), 0, 2);

    return std::shared_ptr<SWInstruction>(new SWInstruction(r, t, offset, line, instructionId));
}