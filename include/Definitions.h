#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <map>

class Instruction;
class Data;

using InstructionMap = std::map<int, std::shared_ptr<Instruction> >; 
using DataMap = std::map<int, std::shared_ptr<Data> >;

#endif