#include "MFHIInstruction.h"

#include <iostream>
#include <sstream>

void MFHIInstruction::execute() {
    std::cout << "Hello world";
}

std::string MFHIInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << "MFHI R" << _dest << std::endl;

    return ss.str();
}

std::shared_ptr<MFHIInstruction> MFHIInstruction::parse(const std::string& line, const int instructionId) {
    auto rt = stoi(line.substr(6, 5), 0, 2);

    return std::shared_ptr<MFHIInstruction>(new MFHIInstruction(rt, line, instructionId));
}