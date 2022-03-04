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

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

shared_ptr<Instruction> Parser::parseLine(const string& line) {
    cout << "Parsing category for instruction line: " << line << " category: " << line.substr(0,3) << endl;

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

    return instruction;
}

shared_ptr<Instruction> Parser::parseCat1Instruction(const string& line) {
    cout << "Parsing opcode for category 1. Opcode: " << line.substr(3,3) << std::endl;

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
    cout << "Parsing opcode for category 2. Opcode: " << line.substr(3,3) << std::endl;

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
    cout << "Parsing opcode for category 3. Opcode: " << line.substr(3,3) << std::endl;

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
    cout << "Parsing opcode for category 4. Opcode: " << line.substr(3,3) << std::endl;

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


shared_ptr<Instruction> Parser::parseCat4Instruction(const string& line) {
    cout << "Parsing opcode for category 4. Opcode: " << line.substr(3,3) << std::endl;

    int opCode = stoi(line.substr(3,3), 0, 2);
    switch (opCode) {
        case INST_MFHI:
        case INST_MFLO:

        default:
            return nullptr;
    }
}

shared_ptr<InstructionVector> Parser::readFile(string& fileName) {
    shared_ptr<InstructionVector> instructions(new InstructionVector());
    Parser parser(START_INSTRUCTION_ADDRESS);

    ifstream file;

    try
    {
        file.open(fileName);
        file.exceptions(std::ifstream::failbit);

        string line; 
        while (getline(file, line)) {
            auto instruction = parser.parseLine(line.substr(0, 32));
            instructions->push_back(move(instruction));
        }
        
        file.close();
    }
    catch(const std::ios_base::failure& fail)
    {
        cerr << "Error opening file: " << fileName << '\n';
    }
    

    return instructions;
}