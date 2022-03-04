#include "SubInstruction.h"

#include <iostream>
#include <sstream>

void SubInstruction::execute() {
    std::cout << "Hello world";
}

std::string SubInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << "SUB " << "R" << _dest << ", R" << _srcOne << ", R" << _srcTwo << std::endl;

    return ss.str();
}

std::shared_ptr<SubInstruction> SubInstruction::parse(const std::string& line, const int instructionId) {
    auto dest = stoi(line.substr(6, 5), 0, 2);
    auto srcOne = stoi(line.substr(11, 5), 0, 2);
    auto srcTwo = stoi(line.substr(16, 5), 0, 2);

    return std::shared_ptr<SubInstruction>(new SubInstruction(dest, srcOne, srcTwo, line, instructionId));
}
