#include "CodeFile.h"

#include <iostream>

void CodeFile::AddCodeFunction(std::string funcName,
                               std::unique_ptr<CodeBlock> codeBlock) {
  codeFunctions_[funcName] =
      std::make_shared<CodeFunction>(std::move(codeBlock));
}

void CodeFile::AddCodeBlock(std::unique_ptr<CodeBlock> codeBlock) {
  codeBlock_ = std::move(codeBlock);
}

CodeBlock CodeFile::Merge() {
  if (codeBlock_) {
    return *codeBlock_;
  }
  std::unique_ptr<CodeBlock> bootCodeBlock = std::make_unique<CodeBlock>();
  std::unique_ptr<CodeBlock> codeBlock = std::make_unique<CodeBlock>();
  for (auto& item : codeFunctions_) {
    if (item.first == "Sys.init")
      bootCodeBlock->extend(item.second->Merge());
    else
      codeBlock->extend(item.second->Merge());
  }
  bootCodeBlock->extend(*codeBlock);
  return *bootCodeBlock;
}