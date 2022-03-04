#include "OrInstruction.h"

#include <iostream>
#include <sstream>

void OrInstruction::execute() {
    std::cout << "Hello world";
}

std::string OrInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << "OR " << "R" << _dest << ", R" << _srcOne << ", R" << _srcTwo << std::endl;

    return ss.str();
}

std::shared_ptr<OrInstruction> OrInstruction::parse(const std::string& line, const int instructionId) {
    auto dest = stoi(line.substr(6, 5), 0, 2);
    auto srcOne = stoi(line.substr(11, 5), 0, 2);
    auto srcTwo = stoi(line.substr(16, 5), 0, 2);

    return std::shared_ptr<OrInstruction>(new OrInstruction(dest, srcOne, srcTwo, line, instructionId));
}
