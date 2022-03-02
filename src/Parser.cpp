#include "AddInstruction.h"
#include "Parser.h"
#include <string>

using namespace std;

Instruction* Parser::parseLine(const string& line) {
    int category = stoi(line.substr(0,2), 0, 2);

    switch (category) {
    case CAT_ONE:
        return parseCat1Instruction(line);
    default:
        break;
    }
    return new AddInstruction();
}

Instruction* Parser::parseCat1Instruction(const string& line) {
    return new AddInstruction();
}