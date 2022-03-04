#include "BreakInstruction.h"

#include <iostream>
#include <sstream>

int BreakInstruction::execute(int* registers, DataMap& data) {
    return PROGRAM_EXIT;
}

std::string BreakInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << getInstructionString() << std::endl;

    return ss.str();
}

std::string BreakInstruction::getInstructionString() {
    std::stringstream ss;
    ss << "BREAK";

    return ss.str();
}

std::shared_ptr<BreakInstruction> BreakInstruction::parse(const std::string& line, const int instructionId) {
    auto code = stoi(line.substr(6, 20), 0, 2);

    return std::shared_ptr<BreakInstruction>(new BreakInstruction(code, line, instructionId));
}