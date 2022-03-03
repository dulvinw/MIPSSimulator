#include "JumpInstruction.h"

#include <iostream>

void JumpInstruction::execute() {
    std::cout << "JINSTRUCTION" << std::endl;
}

void JumpInstruction::print() {
    std::cout << "J" << std::endl;
}

std::shared_ptr<JumpInstruction> JumpInstruction::parse(const std::string& line) {
    return nullptr;
}