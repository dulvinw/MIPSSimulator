#ifndef PARSER_H
#define PARSER_H

#include "AddInstruction.h"
#include <string>

using namespace std;

class Parser {

private:
    shared_ptr<Instruction> parseCat1Instruction(const string& line);
    shared_ptr<Instruction> parseCat2Instruction(const string& line);
    shared_ptr<Instruction> parseCat3Instruction(const string& line);
    shared_ptr<Instruction> parseCat4Instruction(const string& line);

public:
    shared_ptr<Instruction> parseLine(const string& line);

private:
    static const int CAT_ONE = 0;
    static const int CAT_TWO = 1;

    // Cat 1 instructions
    static const int INST_J = 0;

    static const int INST_ADD = 0;
};

#endif