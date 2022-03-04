#include "MFLOInstruction.h"

#include <iostream>
#include <sstream>

void MFLOInstruction::execute() {
    std::cout << "Hello world";
}

std::string MFLOInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << getInstructionString() << std::endl;

    return ss.str();
}

std::string MFLOInstruction::getInstructionString() {
    std::stringstream ss;
    ss << "MFLO R" << _dest;

    return ss.str();
}

std::shared_ptr<MFLOInstruction> MFLOInstruction::parse(const std::string& line, const int instructionId) {
    auto rt = stoi(line.substr(6, 5), 0, 2);

    return std::shared_ptr<MFLOInstruction>(new MFLOInstruction(rt, line, instructionId));
}