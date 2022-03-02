#ifndef PARSER_H
#define PARSER_H

#include "AddInstruction.h"
#include <string>

using namespace std;

class Parser {

private:
    Instruction* parseCat1Instruction(const string& line);
    Instruction* parseCat2Instruction(const string& line);
    Instruction* parseCat3Instruction(const string& line);
    Instruction* parseCat4Instruction(const string& line);

public:
    Instruction* parseLine(const string& line);

private:
    static const int CAT_ONE = 0;
};

#endif