#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "Instruction.h"
#include "Data.h"

#include <map>

using InstructionMap = std::map<int, std::shared_ptr<Instruction> >; 
using DataMap = std::map<int, std::shared_ptr<Data> >;

static const int START_INSTRUCTION_ADDRESS = 256;

#endif