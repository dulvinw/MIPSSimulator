#include "AddInstruction.h"
#include "Definitions.h"
#include "Parser.h"
#include "Constants.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void dessemble(Parser& parser) {

    ofstream disassemble;

    try
    {
        disassemble.open(DISASSEMBLE_FILE_NAME);
        disassemble.exceptions(std::ifstream::failbit);
        for (auto instruction : parser.getInstructions()) {
            if (instruction.second == nullptr)
                continue;
            disassemble << instruction.second->decode();
        }

        for (auto data : parser.getData()) {
            disassemble << data.second->decode();
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
    Parser parser(START_INSTRUCTION_ADDRESS, fileName);

    parser.readFile();

    dessemble(parser);
    return 0;
}