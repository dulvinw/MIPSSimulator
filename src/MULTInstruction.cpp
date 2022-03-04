#include "MULTInstruction.h"

#include <iostream>
#include <sstream>

int MULTInstruction::execute(int* registers, DataMap& data) {
    int64_t result = registers[_rs] * registers[_rt];
    int32_t hi  = ((result & 0xFFFFFFFF00000000LL) >> 32);
    int32_t lo = (result & 0xFFFFFFFFLL);

    registers[HI_REGISTER_ADDRESS] = hi;
    registers[LO_REGISTER_ADDRESS] = lo;

    return _instructionId + NEXT_INSTRUCTION_OFFSET;
}

std::string MULTInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << getInstructionString() << std::endl;

    return ss.str();
}

std::string MULTInstruction::getInstructionString() {
    std::stringstream ss;
    ss << "MULT R" << _rt << ", R" << _rs;

    return ss.str();
}

std::shared_ptr<MULTInstruction> MULTInstruction::parse(const std::string& line, const int instructionId) {
    auto rt = stoi(line.substr(6, 5), 0, 2);
    auto rs = stoi(line.substr(11, 5), 0, 2);

    return std::shared_ptr<MULTInstruction>(new MULTInstruction(rt, rs, line, instructionId));
}