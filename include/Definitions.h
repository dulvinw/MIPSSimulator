#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <map>

class Instruction;
class Data;

using InstructionMap = std::map<int, Instruction*>; 
using DataMap = std::map<int, Data*>;

using InstructionPair = std::pair<int, Instruction*>;
using DataPair = std::pair<int, Data*>;

#endif