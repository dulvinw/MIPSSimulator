#include "BGTZInstruction.h"

#include <iostream>
#include <sstream>

int BGTZInstruction::execute(int* registers, DataMap& data) {
    if (registers[_r] > 0)
        return _instructionId + _offset + NEXT_INSTRUCTION_OFFSET;
    return _instructionId + NEXT_INSTRUCTION_OFFSET;
}

std::string BGTZInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << getInstructionString() << std::endl;

    return ss.str();
}

std::shared_ptr<BGTZInstruction> BGTZInstruction::parse(const std::string& line, const int instructionId) {
    auto r = stoi(line.substr(6, 5), 0, 2);
    auto offset = getOffset(line.substr(16, 16));

    return std::shared_ptr<BGTZInstruction>(new BGTZInstruction(r, offset, line, instructionId));
}

std::string BGTZInstruction::getInstructionString() {
    std::stringstream ss;
    ss << "BGTZ " << "R" << _r << ", #" << _offset;

    return ss.str();
}

int BGTZInstruction::getOffset(const std::string& line) {
    std::string shiftedString = line.substr(2) + "00";
    auto ul = std::stoul(shiftedString, nullptr, 2);
    int signedVal = ul;

    return signedVal;
}