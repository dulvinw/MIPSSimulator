#include "BNEInstruction.h"

#include <iostream>
#include <sstream>

void BNEInstruction::execute() {
    std::cout << "Hello world";
}

std::string BNEInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << "BNE " << "R" << _r << ", R" << _t << ", #" << _offset << std::endl;

    return ss.str();
}

std::shared_ptr<BNEInstruction> BNEInstruction::parse(const std::string& line, const int instructionId) {
    auto r = stoi(line.substr(6, 5), 0, 2);
    auto t = stoi(line.substr(11, 5), 0, 2);
    auto offset = getOffset(line.substr(16, 16));

    return std::shared_ptr<BNEInstruction>(new BNEInstruction(r, t, offset, line, instructionId));
}

int BNEInstruction::getOffset(const std::string& line) {
    std::string shiftedString = line.substr(2) + "00";
    auto ul = std::stoul(shiftedString, nullptr, 2);
    int signedVal = ul;

    return signedVal;
}