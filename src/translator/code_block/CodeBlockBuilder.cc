#include "CodeBlockBuilder.h"

#include <utility>

CodeBlockBuilder::CodeBlockBuilder() {
  codeBlock_ = std::make_unique<CodeBlock>();
}

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
  return tempPtr;
}

bool CodeBlockBuilder::IsEmpty() { return codeBlock_->codes_.empty(); }
