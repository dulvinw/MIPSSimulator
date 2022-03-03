#include "AddInstruction.h"
#include "Parser.h"
#include "JumpInstruction.h"

#include <string>
#include <iostream>

using namespace std;

shared_ptr<Instruction> Parser::parseLine(const string& line) {
    cout << "Parsing category for instruction line: " << line << " category: " << line.substr(0,3) << endl;

    int category = stoi(line.substr(0,3), 0, 2);

    switch (category) {
        case CAT_ONE:
            return parseCat1Instruction(line);
        case CAT_TWO:
            return parseCat2Instruction(line);
        default:
            return nullptr;
    }
}

shared_ptr<Instruction> Parser::parseCat1Instruction(const string& line) {
    cout << "Parsing opcode for category 1. Opcode: " << line.substr(3,3) << std::endl;

    int opCode = stoi(line.substr(3,3), 0, 2);
    switch (opCode) {
        case INST_J:
            return JumpInstruction::parse(line);

        default:
            return nullptr;
    }
}


shared_ptr<Instruction> Parser::parseCat2Instruction(const string& line) {
    cout << "Parsing opcode for category 2. Opcode: " << line.substr(3,3) << std::endl;


    int opCode = stoi(line.substr(3,3), 0, 2);
    switch (opCode) {
        case INST_ADD:
            return AddInstruction::parse(line);

        default:
            return nullptr;
    }
}