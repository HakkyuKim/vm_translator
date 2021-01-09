#ifndef FLAT_FILE_READER_H_
#define FLAT_FILE_READER_H_

#include <string>
#include <fstream>

class LineReader {
    public:
        LineReader(std::string filePath);
        ~LineReader();
        std::string ReadNextLine();
        bool IsEof();
    private:
        std::ifstream stream_;
        std::string filePath_;
};

#endif