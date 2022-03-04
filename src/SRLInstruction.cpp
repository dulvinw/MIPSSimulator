#include "SRLInstruction.h"

#include <iostream>
#include <sstream>

void SRLInstruction::execute() {
    std::cout << "Hello world";
}

std::string SRLInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << getInstructionString() << std::endl;

    return ss.str();
}

std::string SRLInstruction::getInstructionString() {
    std::stringstream ss;
    ss << "SRA " << "R" << _dest << ", R" << _srcOne << ", #" << _immediate;

    return ss.str();
}

std::shared_ptr<SRLInstruction> SRLInstruction::parse(const std::string& line, const int instructionId) {
    auto dest = stoi(line.substr(6, 5), 0, 2);
    auto srcOne = stoi(line.substr(11, 5), 0, 2);
    auto immediate = stoi(line.substr(16, 5), 0, 2);

    return std::shared_ptr<SRLInstruction>(new SRLInstruction(dest, srcOne, immediate, line, instructionId));
}