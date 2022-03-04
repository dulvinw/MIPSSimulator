#include "AddInstruction.h"
#include "Parser.h"
#include "JumpInstruction.h"
#include "BEQInstruction.h"
#include "BNEInstruction.h"
#include "BGTZInstruction.h"
#include "SWInstruction.h"
#include "LWInstruction.h"
#include "BreakInstruction.h"
#include "SubInstruction.h"
#include "AndInstruction.h"
#include "SRLInstruction.h"
#include "SRAInstruction.h"
#include "AndIInstruction.h"
#include "AddIInstruction.h"
#include "OrIInstruction.h"
#include "MULTInstruction.h"
#include "DIVInstruction.h"
#include "MFHIInstruction.h"
#include "MFLOInstruction.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

std::pair<int, shared_ptr<Instruction> > Parser::parseInstruction(const string& line) {
    int category = stoi(line.substr(0,3), 0, 2);

    shared_ptr<Instruction> instruction;
    switch (category) {
        case CAT_ONE:
            instruction = parseCat1Instruction(line);
            break;
        case CAT_TWO:
            instruction = parseCat2Instruction(line);
            break;
        case CAT_THREE:
            instruction = parseCat3Instruction(line);
            break;
        case CAT_FOUR:
            instruction = parseCat4Instruction(line);
            break;
        case CAT_FIVE:
            instruction = parseCat5Instruction(line);
            break;

        default:
            instruction = nullptr;
    }

    this->_instructionId += 4;

    return std::pair<int, std::shared_ptr<Instruction> > (_instructionId-4, instruction);
}

shared_ptr<Instruction> Parser::parseCat1Instruction(const string& line) {
    int opCode = stoi(line.substr(3,3), 0, 2);
    switch (opCode) {
        case INST_J:
            return JumpInstruction::parse(line, this->_instructionId);
        case INST_BEQ:
            return BEQInstruction::parse(line, this->_instructionId);
        case INST_BNE:
            return BNEInstruction::parse(line, this->_instructionId);
        case INST_BGTZ:
            return BGTZInstruction::parse(line, this->_instructionId);
        case INST_SW:
            return SWInstruction::parse(line, this->_instructionId); 
        case INST_LW:
            return LWInstruction::parse(line, this->_instructionId); 
        case INST_BREAK:
            return BreakInstruction::parse(line, this->_instructionId);

        default:
            return nullptr;
    }
}


shared_ptr<Instruction> Parser::parseCat2Instruction(const string& line) {
    int opCode = stoi(line.substr(3,3), 0, 2);
    switch (opCode) {
        case INST_ADD:
            return AddInstruction::parse(line, this->_instructionId);
        case INST_SUB:
            return SubInstruction::parse(line, this->_instructionId);
        case INST_AND:
            return AndInstruction::parse(line, this->_instructionId);
        case INST_SRL:
            return SRLInstruction::parse(line, this->_instructionId);
        case INST_SRA:
            return SRAInstruction::parse(line, this->_instructionId);
        default:
            return nullptr;
    }
}


shared_ptr<Instruction> Parser::parseCat3Instruction(const string& line) {
    int opCode = stoi(line.substr(3,3), 0, 2);
    switch (opCode) {
        case INST_ADDI:
            return AddIInstruction::parse(line, this->_instructionId);
        case INST_ANDI:
            return AndIInstruction::parse(line, this->_instructionId);
        case INST_ORI:
            return OrIInstruction::parse(line, this->_instructionId);
        default:
            return nullptr;
    }
}

shared_ptr<Instruction> Parser::parseCat4Instruction(const string& line) {
    int opCode = stoi(line.substr(3,3), 0, 2);
    switch (opCode) {
        case INST_MULT:
            return MULTInstruction::parse(line, this->_instructionId);
        case INST_DIV:
            return DIVInstruction::parse(line, this->_instructionId);

        default:
            return nullptr;
    }
}


shared_ptr<Instruction> Parser::parseCat5Instruction(const string& line) {
    int opCode = stoi(line.substr(3,3), 0, 2);
    switch (opCode) {
        case INST_MFHI:
            return MFHIInstruction::parse(line, this->_instructionId);
        case INST_MFLO:
            return MFLOInstruction::parse(line, this->_instructionId);

        default:
            return nullptr;
    }
}

void Parser::readFile() {
    ifstream file;

    try
    {
        file.open(_fileName);
        file.exceptions(std::ifstream::failbit);

        string line; 
        while (getline(file, line)) {
            auto instruction = parseInstruction(line.substr(0, 32));
            _instructions.insert(instruction);

            auto breakInstruction = dynamic_cast<BreakInstruction*>(instruction.second.get());
            if (breakInstruction) {
                break;
            }
        }

        // Parse Data memory
        while (getline(file, line)) {
            _data.insert(parseData(line));
        }
        
        file.close();
    }
    catch(const std::ios_base::failure& fail)
    {

    }
}

std::pair<int, std::shared_ptr<Data> > Parser::parseData(const string& line) {
    auto raw = stoul(line.substr(0, 32), nullptr, 2);
    int compliment = int(raw);
    auto data = std::shared_ptr<Data>(new Data(line.substr(0, 32), _instructionId, compliment));

    _instructionId += 4;

    return std::pair<int, std::shared_ptr<Data> >(_instructionId-4, data);
}