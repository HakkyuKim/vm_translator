#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "src/parser/Parser.h"
#include "src/translator/Translator.h"

/**
 * The program takes 3 command-line arguments:
 *   argv[0]: the name of the program
 *   argv[1]: the input file/directory path
 *   argv[2]: the output file
 **/
int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cout << "Insufficient arguments\n";
    return EXIT_FAILURE;
  }
  std::string inputFilePath = argv[1];
  std::string inputFileName =
      std::filesystem::path(argv[1]).filename().string();
  std::string inputFilePathAbs = std::filesystem::absolute(argv[1]);

  std::string outputFilePath = argv[2];
  std::string outputFilePathAbs = std::filesystem::absolute(argv[2]);

  std::string fileName =
      std::filesystem::path(argv[1]).filename().replace_extension().string();
  // check if path is file or directory
  // if file -> outputfile = path(filePath).replace_extension(".out")
  // if directory -> outputfile = path(dirPath) + "/" +
  // basename(dirPath).replace_extension(".out")

  // file_system walk
  // codeWriterRead
  Parser parser;
  Translator translator;
  parser.SetFile(inputFilePathAbs);
  translator.SetFile(inputFileName);

  std::cout << "input: " + inputFilePathAbs + "\n";
  std::ofstream of = std::ofstream(outputFilePathAbs);
  try {
    while (!parser.IsEof()) {
      ParseResult parseResult = parser.ParseNextLine();
      if (parseResult.parseType == ParseType::COMMENT ||
          parseResult.parseType == ParseType::WHITESPACE) {
        continue;
      }
      translator.FeedLine(std::move(parseResult.token));
    }
    translator.CloseFile();
  } catch (std::exception& e) {
    std::cout << e.what();
    return EXIT_FAILURE;
  }
  of << translator.Code();
  return EXIT_SUCCESS;
}