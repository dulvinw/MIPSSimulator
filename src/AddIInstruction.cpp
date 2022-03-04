#include "AddIInstruction.h"

#include <iostream>
#include <sstream>

void AddIInstruction::execute() {
    std::cout << "Hello world";
}

std::string AddIInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << getInstructionString() << std::endl;

    return ss.str();
}

std::string AddIInstruction::getInstructionString() {
    std::stringstream ss;
    ss << "ADDI " << "R" << _dest << ", R" << _srcOne << ", #" << _immediate;

    return ss.str();
}


std::shared_ptr<AddIInstruction> AddIInstruction::parse(const std::string& line, const int instructionId) {
    auto dest = stoi(line.substr(6, 5), 0, 2);
    auto srcOne = stoi(line.substr(11, 5), 0, 2);
    auto immediate = stoi(line.substr(16, 16), 0, 2);

    return std::shared_ptr<AddIInstruction>(new AddIInstruction(dest, srcOne, immediate, line, instructionId));
}