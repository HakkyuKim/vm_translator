#include "DecodeResult.h"

DecodeResult::DecodeResult(bool hasCodeBlock, bool isFunction,
                           std::unique_ptr<CodeBlock> codeBlock,
                           std::string fileName, std::string funcName)
    : hasCodeBlock(hasCodeBlock),
      isFunction(isFunction),
      codeBlock(std::move(codeBlock)),
      fileName(fileName),
      funcName(funcName) {}
