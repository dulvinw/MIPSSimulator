#include "AddInstruction.h"
#include "Definitions.h"
#include "Parser.h"

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

shared_ptr<InstructionVector> readFile(string& fileName) {
    shared_ptr<InstructionVector> instructions(new InstructionVector());
    Parser parser;

    ifstream file;

    try
    {
        file.open(fileName);
        file.exceptions(std::ifstream::failbit);

        string line; 
        while (getline(file, line)) {
            auto instruction = parser.parseLine(line);
            instructions->push_back(move(instruction));
        }
        
    }
    catch(const std::ios_base::failure& fail)
    {
        cerr << "Error opening file: " << fileName << '\n';
    }
    

    return instructions;
}

void dessemble(shared_ptr<InstructionVector> instructions) {
    for (auto instruction : *instructions) {
        if (instruction == nullptr)
            continue;
        instruction->print();
    }
}

int main(int argc, char* argv[]) {
    string fileName(argv[1]);
    auto instructions = readFile(fileName);

    dessemble(instructions);
    return 0;
}