#include "AndInstruction.h"

#include <iostream>
#include <sstream>

void AndInstruction::execute() {
    std::cout << "Hello world";
}

std::string AndInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() <<  getInstructionString() << std::endl;

    return ss.str();
}

std::string AndInstruction::getInstructionString() {
    std::stringstream ss;
    ss << "AND " << "R" << _dest << ", R" << _srcOne << ", R" << _srcTwo;

    return ss.str();
}

std::shared_ptr<AndInstruction> AndInstruction::parse(const std::string& line, const int instructionId) {
    auto dest = stoi(line.substr(6, 5), 0, 2);
    auto srcOne = stoi(line.substr(11, 5), 0, 2);
    auto srcTwo = stoi(line.substr(16, 5), 0, 2);

    return std::shared_ptr<AndInstruction>(new AndInstruction(dest, srcOne, srcTwo, line, instructionId));
}
