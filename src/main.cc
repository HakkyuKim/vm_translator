#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "LineReader.h"
#include "Parser.h"
#include "CodeWriter.h"

/**
* The program takes 3 command-line arguments:
*   argv[0]: the name of the program
*   argv[1]: the input file/directory path
*   argv[2]: the output file
**/
int main(int argc, char *argv[]){
    if(argc < 3){
        std::cout << "Insufficient arguments\n";
        return EXIT_FAILURE;
    }
    std::string inputFilePath = argv[1];
    std::string outputFilePath = argv[2];
    std::string fileName = std::filesystem::path(argv[1]).filename().replace_extension().string();
    // check if path is file or directory
    // if file -> outputfile = path(filePath).replace_extension(".out")
    // if directory -> outputfile = path(dirPath) + "/" + basename(dirPath).replace_extension(".out")

    // file_system walk
    // codeWriterRead

    LineReader lineReader(inputFilePath);
    Parser parser;
    CodeWriter codeWriter(fileName);

    std::ofstream of = std::ofstream(outputFilePath);
    while(!lineReader.IsEof()){ // read by line
        std::string vmCodeLine = lineReader.ReadNextLine(); // reader
        ParseResult parseResult = parser.parse(vmCodeLine); // parser
        if(parseResult.parseType == ParseType::COMMENT || parseResult.parseType == ParseType::WHITESPACE){
            continue;
        }
        codeWriter.Decode(parseResult.tokens);
    }
    of << codeWriter.GenerateCode().String();
    return EXIT_SUCCESS;
}