#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "LineReader.h"
#include "Parser.h"
#include "CodeWriter.h"

int main(int argc, char *argv[]){
    if(argc < 3){
        std::cout << "Insufficient arguments\n";
        return EXIT_FAILURE;
    }
    std::string inputFilePath = argv[1];
    std::string outputFilePath = argv[2];
    std::string fileName = std::filesystem::path(argv[1]).filename().replace_extension().string();

    LineReader lineReader(inputFilePath);
    Parser parser;
    CodeWriter codeWriter(fileName);

    std::ofstream of = std::ofstream(outputFilePath);
    while(!lineReader.IsEof()){
        std::string vmCodeLine = lineReader.ReadNextLine();
        ParseResult parseResult = parser.parse(vmCodeLine);
        if(parseResult.parseType == ParseType::COMMENT || parseResult.parseType == ParseType::WHITESPACE){
            continue;
        }
        of << codeWriter.Decode(*parseResult.tokens).String();
    }
    return EXIT_SUCCESS;
}