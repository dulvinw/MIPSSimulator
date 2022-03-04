#ifndef DATA_H
#define DATA_H

#include <string>
#include <sstream>

class Data {
public:

    Data(const std::string& line, const int instructionId, const int data) : _line(line), _instructionId(instructionId), _data(data) {}

    std::string decode() {
        std::stringstream ss;

        ss << _line << "\t" << _instructionId << "\t\t" << _data << std::endl; 

        return ss.str();
    }

    Data() = delete;

public:
    const std::string _line;
    const int _instructionId;
    int _data;
};

#endif