#ifndef EXECUTION_ENGINE_H
#define EXECUTION_ENGINE_H

#include "Parser.h"
#include "Constants.h"

#include <fstream>

class ExecutionEngine {

public:
    ExecutionEngine(Parser& parser) : _parser(parser) {
        for (int i = 0; i < (NUM_OF_REGISTERS+NUM_OF_SPECIAL_REG); i++) {
            _registers[i] = 0;
        }
        
    }

    void execute();

private:
    void executeInstruction(std::ofstream& file);
    void printHeader(std::ofstream& file, Instruction* instruction, const int count);
    void printData(std::ofstream& file, DataMap& data);
    void printRegisters(std::ofstream& file);
    void printFirstColumnInRegisterReport(std::ofstream& file, const int i);
    void printFirstColumnInDataReport(std::ofstream& file, const int i);
    Instruction* getNextInstruction(InstructionMap& instructions, const int address);

private:
    Parser& _parser;
    int _registers[NUM_OF_REGISTERS+NUM_OF_SPECIAL_REG];
};

#endif