#ifndef EXECUTION_ENGINE_H
#define EXECUTION_ENGINE_H

#include "Parser.h"
#include "Constants.h"

#include <fstream>

class ExecutionEngine {

public:
    ExecutionEngine(Parser& parser) : _parser(parser) {
        for (int i = 0; i < NUM_OF_REGISTERS; i++) {
            _registers[i] = 0;
        }
        
    }

    void execute();

private:
    void executeInstruction(std::ofstream& file);
    void printHeader(std::ofstream& file, shared_ptr<Instruction> instruction, const int count);
    void printData(std::ofstream& file, DataMap& data);
    void printRegisters(std::ofstream& file);
    void printFirstColumnInRegisterReport(std::ofstream& file, const int i);
    void printFirstColumnInDataReport(std::ofstream& file, const int i);

private:
    Parser& _parser;
    int _registers[NUM_OF_REGISTERS];
};

#endif