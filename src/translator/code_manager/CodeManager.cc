#include "CodeManager.h"

#include <iostream>

void CodeManager::CreateCodeFile(std::string fileName) {
  codeFiles_[fileName] = std::make_shared<CodeFile>();
}

void CodeManager::AddCodeToCodeFile(std::string fileName,
                                    std::unique_ptr<CodeBlock> codeBlock) {
  if (codeFiles_[fileName] == nullptr) {
    throw new std::invalid_argument(fileName + " is not saved\n");
  }
  codeFiles_[fileName]->AddCodeBlock(std::move(codeBlock));
}

void CodeManager::AddCodeToCodeFunction(std::string fileName,
                                        std::string funcName,
                                        std::unique_ptr<CodeBlock> codeBlock) {
  codeFiles_[fileName]->AddCodeFunction(funcName, std::move(codeBlock));
}

CodeBlock CodeManager::Merge() {
  std::unique_ptr<CodeBlock> asmCodeBlock = std::make_unique<CodeBlock>();
  std::unique_ptr<CodeBlock> codeBlock = std::make_unique<CodeBlock>();
  for (auto& item : codeFiles_) {
    if (item.first == "Sys.vm" || item.first == "Sys") {
      asmCodeBlock->extend(item.second->Merge());
    } else {
      codeBlock->extend(item.second->Merge());
    }
  }
  asmCodeBlock->extend(*codeBlock);
  return *asmCodeBlock;
}
