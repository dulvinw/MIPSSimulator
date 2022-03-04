#include "BreakInstruction.h"

#include <iostream>
#include <sstream>

void BreakInstruction::execute() {
    std::cout << "Hello world";
}

std::string BreakInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << "BREAK" << std::endl;

    return ss.str();
}

std::shared_ptr<BreakInstruction> BreakInstruction::parse(const std::string& line, const int instructionId) {
    auto code = stoi(line.substr(6, 20), 0, 2);

    return std::shared_ptr<BreakInstruction>(new BreakInstruction(code, line, instructionId));
}