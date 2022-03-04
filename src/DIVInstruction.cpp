#include "DIVInstruction.h"

#include <iostream>
#include <sstream>

void DIVInstruction::execute() {
    std::cout << "Hello world";
}

std::string DIVInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << "MULT R" << _rt << ", R" << _rs << std::endl;

    return ss.str();
}

std::shared_ptr<DIVInstruction> DIVInstruction::parse(const std::string& line, const int instructionId) {
    auto rt = stoi(line.substr(6, 5), 0, 2);
    auto rs = stoi(line.substr(11, 5), 0, 2);

    return std::shared_ptr<DIVInstruction>(new DIVInstruction(rt, rs, line, instructionId));
}