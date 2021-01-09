#include "LineReader.h"

LineReader::LineReader(std::string filePath) 
{
    filePath_ = filePath;
    stream_ = std::ifstream(filePath_, std::ios::in);
}

LineReader::~LineReader() 
{
    stream_.clear();
}

std::string LineReader::ReadNextLine() 
{
    std::string line;
    while(stream_.good()){
        char c = stream_.get();
        if(c == '\n' || c == EOF){
            return line;
        }
        line.push_back(c);
    }
    return line;
}

bool LineReader::IsEof() 
{
    return stream_.eof();
}
