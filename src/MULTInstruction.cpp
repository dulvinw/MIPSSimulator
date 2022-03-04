#include "MULTInstruction.h"

#include <iostream>
#include <sstream>

void MULTInstruction::execute() {
    std::cout << "Hello world";
}

std::string MULTInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << getInstructionString() << std::endl;

    return ss.str();
}

std::string MULTInstruction::getInstructionString() {
    std::stringstream ss;
    ss << "MULT R" << _rt << ", R" << _rs;

    return ss.str();
}

std::shared_ptr<MULTInstruction> MULTInstruction::parse(const std::string& line, const int instructionId) {
    auto rt = stoi(line.substr(6, 5), 0, 2);
    auto rs = stoi(line.substr(11, 5), 0, 2);

    return std::shared_ptr<MULTInstruction>(new MULTInstruction(rt, rs, line, instructionId));
}