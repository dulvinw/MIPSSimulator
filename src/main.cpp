#include "AddInstruction.h"
#include "Definitions.h"
#include "Parser.h"
#include "Constants.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;



void dessemble(shared_ptr<InstructionVector> instructions) {

    ofstream disassemble;

    try
    {
        disassemble.open(DISASSEMBLE_FILE_NAME);
        disassemble.exceptions(std::ifstream::failbit);
        for (auto instruction : *instructions) {
            if (instruction == nullptr)
                continue;
            disassemble << instruction->decode();
        }

        disassemble.close();
    }
    catch(const std::ios_base::failure& fail)
    {
        cerr << "Error opening file: " << DISASSEMBLE_FILE_NAME << '\n';
    }
    
}

int main(int argc, char* argv[]) {
    string fileName(argv[1]);
    auto instructions = Parser::readFile(fileName);

    dessemble(instructions);
    return 0;
}