#include "ExecutionEngine.h"
#include "Constants.h"
#include "Definitions.h"
#include "BreakInstruction.h"

#include <fstream>
#include <iostream>

void ExecutionEngine::execute() {
    ofstream file;

    try
    {
        file.open(SIMULATION_FILE_NAME);
        file.exceptions(std::ofstream::failbit);
        executeInstruction(file);
        file.close();

    } catch(const std::ios_base::failure& fail) {
        std::cerr << "Error opening file: " << SIMULATION_FILE_NAME << '\n';
    } 

    
}

void ExecutionEngine::executeInstruction(std::ofstream& file) {
    auto instructions = _parser.getInstructions();
    auto data = _parser.getData();

    int cycleCount = 1;
    auto instruction = getNextInstruction(instructions, START_INSTRUCTION_ADDRESS);
    while (instruction != nullptr) {
        printHeader(file, instruction, cycleCount);
        auto nextAddress = instruction->execute(_registers, data);
        printRegisters(file);
        printData(file, data);

        instruction = getNextInstruction(instructions, nextAddress);
        cycleCount++;
    }
}

shared_ptr<Instruction> ExecutionEngine::getNextInstruction(InstructionMap& instructions, const int address) {
    auto currInstruction = instructions.find(address);
    if (currInstruction == instructions.end()) {
        return nullptr;
    }

    if (address == PROGRAM_EXIT)
        return nullptr;

    return currInstruction->second;
}

void ExecutionEngine::printHeader(std::ofstream& file, std::shared_ptr<Instruction> instruction, const int cycleCount) {
        file << "--------------------" << std::endl;
        file << "Cycle " << cycleCount << ":\t" << instruction->getInstructionId() << "\t\t" << instruction->getInstructionString() << std::endl;
        file << std::endl;
}

void ExecutionEngine::printData(std::ofstream& file, DataMap& data) {
    file << "Data";

    int columnCount = 0;
    for (auto entry : data) {
        if ((columnCount % NUM_OF_COLUMNS_IN_DATA_REPORT) == 0) {
            file << std::endl;
            file << entry.first << ":\t";
        }

        file << entry.second->_data << "\t";
        
        columnCount++;
    }

    file << std::endl;
    file << std::endl;
}


void ExecutionEngine::printRegisters(std::ofstream& file) {
    file << "Registers";
    for (int i = 0; i < NUM_OF_REGISTERS; i++) {
        if ((i % NUM_OF_COLUMNS_IN_REGISTER_REPORT) == 0)
            printFirstColumnInRegisterReport(file, i);
        
        file << _registers[i] << "\t";
    }

    file << std::endl;
    file << std::endl;
}

void ExecutionEngine::printFirstColumnInRegisterReport(std::ofstream& file, const int i) {
    file << std::endl;

    if (i < 10) {
        file << "R0" << i << ":\t";
    } else {
        file << "R" << i << ":\t";
    }
}