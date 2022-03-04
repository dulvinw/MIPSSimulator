#include "LWInstruction.h"

#include <iostream>
#include <sstream>

void LWInstruction::execute() {
    std::cout << "Hello world";
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

std::shared_ptr<LWInstruction> LWInstruction::parse(const std::string& line, const int instructionId) {
    auto r = stoi(line.substr(6, 5), 0, 2);
    auto t = stoi(line.substr(11, 5), 0, 2);
    auto offset = stoi(line.substr(16, 16), 0, 2);

    return std::shared_ptr<LWInstruction>(new LWInstruction(r, t, offset, line, instructionId));
}