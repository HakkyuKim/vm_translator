#ifndef __CODEFUNCTION_H__
#define __CODEFUNCTION_H__

#include <memory>

#include "src/translator/code_block/CodeBlock.h"

class CodeFunction {
 public:
  CodeFunction(std::unique_ptr<CodeBlock> codeBlock);
  CodeBlock Merge();

 private:
  std::unique_ptr<CodeBlock> codeBlock_;
};

#endif  // __CODEFUNCTION_H__