#include "AddInstruction.h"
#include "Definitions.h"
#include "Parser.h"

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

unique_ptr<InstructionVector> readFile(string& fileName) {
    unique_ptr<InstructionVector> instructions(new InstructionVector());
    Parser parser;

    ifstream file;

    try
    {
        file.open(fileName);
        file.exceptions(std::ifstream::failbit);

        string line; 
        while (getline(file, line)) {
            auto instruction = parser.parseLine(line);
            instructions->push_back(instruction);
        }
        
    }
    catch(const std::ios_base::failure& fail)
    {
        cerr << "Error opening file: " << fileName << '\n';
    }
    

    return instructions;
}

int main() {
    AddInstruction addInstruction;

    addInstruction.execute();
    return 0;
}