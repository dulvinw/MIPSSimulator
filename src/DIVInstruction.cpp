#include "DIVInstruction.h"

#include <iostream>
#include <sstream>

int DIVInstruction::execute(int* registers, DataMap& data) {
    int quotient = registers[_rt] / registers[_rs];
    int remainder = registers[_rt] % registers[_rs];

    registers[HI_REGISTER_ADDRESS] = remainder;
    registers[LO_REGISTER_ADDRESS] = quotient;

    return _instructionId + NEXT_INSTRUCTION_OFFSET;
}

std::string DIVInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << getInstructionString() << std::endl;

    return ss.str();
}

std::string DIVInstruction::getInstructionString() {
    std::stringstream ss;
    ss <<  "MULT R" << _rt << ", R" << _rs;

    return ss.str();
}
std::shared_ptr<DIVInstruction> DIVInstruction::parse(const std::string& line, const int instructionId) {
    auto rt = stoi(line.substr(6, 5), 0, 2);
    auto rs = stoi(line.substr(11, 5), 0, 2);

    return std::shared_ptr<DIVInstruction>(new DIVInstruction(rt, rs, line, instructionId));
}