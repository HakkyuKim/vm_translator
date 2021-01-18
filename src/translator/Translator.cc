#include "Translator.h"

#include <iostream>

#include "src/translator/decoder/DecodeResult.h"

Translator::Translator() {}

Translator::~Translator() {}

void Translator::FeedLine(std::unique_ptr<TokenBase> token) {
  decoder_.FeedLine(std::move(token));
}

void Translator::CloseFile() {
  std::cout << "closing file\n";
  decoder_.CloseFile();
}

void Translator::ProcessDecodeResult() {
  while (!decoder_.IsResultEmpty()) {
    std::shared_ptr<DecodeResult> result = decoder_.Poll();
    if (result->hasCodeBlock) {
      if (result->isFunction) {
        codeManager_.AddCodeToCodeFunction(result->fileName, result->funcName,
                                           std::move(result->codeBlock));
      } else {
        codeManager_.AddCodeToCodeFile(result->fileName,
                                       std::move(result->codeBlock));
      }
    }
  }
}

void Translator::SetFile(std::string fileName) {
  decoder_.SetFile(fileName);
  codeManager_.CreateCodeFile(fileName);
}

std::string Translator::Code() { return codeManager_.Merge().String(); }
