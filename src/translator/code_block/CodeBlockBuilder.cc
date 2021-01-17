#include "CodeBlockBuilder.h"

#include <utility>

CodeBlockBuilder& CodeBlockBuilder::WriteLine(std::string line) {
  codeBlock_->codes_.push_back(line);
  return *this;
}

CodeBlockBuilder& CodeBlockBuilder::Extend(CodeBlock codeBlock) {
  codeBlock_->extend(codeBlock);
  return *this;
}

std::unique_ptr<CodeBlock> CodeBlockBuilder::build() {
  std::unique_ptr<CodeBlock> tempPtr = std::move(codeBlock_);
  codeBlock_ = std::make_unique<CodeBlock>();
  return std::move(tempPtr);
}

uint32_t CodeBlockBuilder::GetLineNumbers() {
  return static_cast<uint32_t>(codeBlock_->codes_.size());
}
