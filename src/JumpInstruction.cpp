#include "JumpInstruction.h"

#include <iostream>
#include <sstream>

int JumpInstruction::execute(int* registers, DataMap& data) {
    return _jumpTo;
}

std::string JumpInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << getInstructionString() << std::endl;

    return ss.str();
}

std::string JumpInstruction::getInstructionString() {
    std::stringstream ss;
    ss << "J #" << _jumpTo;

    return ss.str();
}

JumpInstruction* JumpInstruction::parse(const std::string& line, const int instructionId) {
    std::string formatted = line.substr(2).append("00");
    auto lowerBits = stoi(formatted, 0, 2); // TODO: Fix this calculation
    auto upperBits = (15 << 28) & (instructionId+4);

    auto instruction = lowerBits | upperBits;

    return new JumpInstruction(instruction, line, instructionId);
}