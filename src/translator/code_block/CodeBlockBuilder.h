#ifndef __CODEBLOCKBUILDER_H__
#define __CODEBLOCKBUILDER_H__

#include <memory>
#include <string>

#include "CodeBlock.h"

class CodeBlockBuilder {
 public:
  CodeBlockBuilder();
  CodeBlockBuilder& WriteLine(std::string line);
  CodeBlockBuilder& Extend(CodeBlock codeBlock);
  std::unique_ptr<CodeBlock> build();
  uint32_t GetLineNumbers();
 private:
  std::unique_ptr<CodeBlock> codeBlock_;
};

#endif  // __CODEBLOCKBUILDER_H__