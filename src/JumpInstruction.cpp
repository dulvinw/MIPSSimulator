#include "JumpInstruction.h"

#include <iostream>
#include <sstream>

void JumpInstruction::execute() {
    std::cout << "JINSTRUCTION" << std::endl;
}

std::string JumpInstruction::decode() {
    std::stringstream ss;
    ss << "J" << std::endl;

    return ss.str();
}

std::shared_ptr<JumpInstruction> JumpInstruction::parse(const std::string& line, const int instructionId) {
    return nullptr;
}