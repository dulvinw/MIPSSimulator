#include "AddInstruction.h"
#include <iostream>

void AddInstruction::execute() {
    std::cout << "Hello world";
}

void AddInstruction::print() {
    std::cout << "Add " << "R" << _dest << ", R" << _srcOne << ", R" << _srcTwo << std::endl;
}

std::shared_ptr<AddInstruction> AddInstruction::parse(const std::string& line) {
    auto dest = stoi(line.substr(6, 5), 0, 2);
    auto srcOne = stoi(line.substr(11, 5), 0, 2);
    auto srcTwo = stoi(line.substr(16, 5), 0, 2);

    return std::shared_ptr<AddInstruction>(new AddInstruction(dest, srcOne, srcTwo));
}
