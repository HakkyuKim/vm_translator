#include "CodeFile.h"

#include <iostream>

void CodeFile::AddCodeFunction(std::string funcName,
                               std::unique_ptr<CodeBlock> codeBlock) {
  codeFunctions_[funcName] =
      std::make_unique<CodeFunction>(std::move(codeBlock));
}

void CodeFile::AddCodeBlock(std::unique_ptr<CodeBlock> codeBlock) {
  codeBlock_ = std::move(codeBlock);
}

CodeBlock CodeFile::Merge() {
  if (codeBlock_) {
    // std::cout << codeBlock_->String();
    return *codeBlock_;
  }
  std::unique_ptr<CodeBlock> codeBlock = std::make_unique<CodeBlock>();
  for (auto& item : codeFunctions_) {
    codeBlock->extend(*item.second->Merge());
  }
  return *codeBlock;
}