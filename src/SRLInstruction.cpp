#include "SRLInstruction.h"

#include <iostream>
#include <sstream>

int SRLInstruction::execute(int* registers, DataMap& data) {
    registers[_dest] = registers[_srcOne] >> _immediate; // need to revist
    return _instructionId + NEXT_INSTRUCTION_OFFSET;
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

SRLInstruction* SRLInstruction::parse(const std::string& line, const int instructionId) {
    auto dest = stoi(line.substr(6, 5), 0, 2);
    auto srcOne = stoi(line.substr(11, 5), 0, 2);
    auto immediate = stoi(line.substr(16, 5), 0, 2);

    return new SRLInstruction(dest, srcOne, immediate, line, instructionId);
}