#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "src/parser/Parser.h"
#include "src/translator/Translator.h"
namespace fs = std::filesystem;

void DecodeSingleFile(std::string filePath, std::string fileName,
                      Parser& parser, Translator& translator) {
  parser.SetFile(filePath);
  translator.SetFile(fileName);

  std::cout << "input: " + filePath + "\n";
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
  }
}

/**
 * The program receives 2 arguments and an optional 3rd argument:
 *   argv[0]: the name of the program
 *   argv[1]: the input file/directory path
 *   argv[2]: the option to add bootstrap code
 *   argv[3]: the initial stack address to set up in bootstrap code
 **/
int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "You haven't specifed an input path\n";
    return EXIT_FAILURE;
  }

  auto inputPath = argv[1];
  auto inputPathAbs = fs::absolute(inputPath);
  auto inputFileName = fs::path(inputPath).filename().replace_extension();
  std::string initialStackAddr =
      (argc >= 4 && !strcmp(argv[2], "-bootstrap")) ? argv[3] : "";

  Parser parser;
  Translator translator;

  auto outputFilePath = inputPathAbs;
  if (fs::is_directory(inputPathAbs)) {
    for (auto& p : fs::directory_iterator(inputPathAbs)) {
      if (p.is_regular_file() && p.path().extension().string() == ".vm") {
        DecodeSingleFile(p.path().string(),
                         p.path().filename().replace_extension().string(),
                         parser, translator);
      }
    }
    std::string outputFileName =
        inputFileName.replace_extension("asm").string();
    outputFilePath = outputFilePath / outputFileName;
  } else {
    DecodeSingleFile(inputPathAbs.string(), inputFileName.string(), parser,
                     translator);
    outputFilePath.replace_extension("asm");
  }

  translator.ProcessDecodeResult();

  std::cout << "Write to " << outputFilePath << "\n";
  std::ofstream of = std::ofstream(outputFilePath.string());
  if (!initialStackAddr.empty())
    of << translator.GetBootStrap(initialStackAddr);
  of << translator.Code();

  return EXIT_SUCCESS;
}