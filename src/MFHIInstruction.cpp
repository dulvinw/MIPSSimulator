#include "MFHIInstruction.h"

#include <iostream>
#include <sstream>

int MFHIInstruction::execute(int* registers, DataMap& data) {
    registers[_dest] = registers[HI_REGISTER_ADDRESS];
    return _instructionId + NEXT_INSTRUCTION_OFFSET;
}

std::string MFHIInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << getInstructionString() << std::endl;

    return ss.str();
}

std::string MFHIInstruction::getInstructionString() {
    std::stringstream ss;
    ss << "MFHI R" << _dest;

    return ss.str();
}

std::shared_ptr<MFHIInstruction> MFHIInstruction::parse(const std::string& line, const int instructionId) {
    auto rt = stoi(line.substr(6, 5), 0, 2);

    return std::shared_ptr<MFHIInstruction>(new MFHIInstruction(rt, line, instructionId));
}