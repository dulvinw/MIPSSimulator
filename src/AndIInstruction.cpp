#include "AndIInstruction.h"

#include <iostream>
#include <sstream>

void AndIInstruction::execute() {
    std::cout << "Hello world";
}

std::string AndIInstruction::decode() {
    std::stringstream ss;
    ss << getPreamble() << "ANDI " << "R" << _dest << ", R" << _srcOne << ", #" << _immediate << std::endl;

    return ss.str();
}
std::shared_ptr<AndIInstruction> AndIInstruction::parse(const std::string& line, const int instructionId) {
    auto dest = stoi(line.substr(6, 5), 0, 2);
    auto srcOne = stoi(line.substr(11, 5), 0, 2);
    auto immediate = stoi(line.substr(16, 5), 0, 2);

    return std::shared_ptr<AndIInstruction>(new AndIInstruction(dest, srcOne, immediate, line, instructionId));
}