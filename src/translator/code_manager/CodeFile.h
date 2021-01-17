#ifndef __CODEFILE_H__
#define __CODEFILE_H__

#include <map>

#include "CodeFunction.h"

class CodeFile {
 public:
  void AddCodeFunction(std::string funcName,
                       std::unique_ptr<CodeBlock> codeBlcok);
  void AddCodeBlock(std::unique_ptr<CodeBlock> codeBlock);
  CodeBlock Merge();

 private:
  std::unique_ptr<CodeBlock> codeBlock_;
  std::map<std::string, std::unique_ptr<CodeFunction>> codeFunctions_;
};

#endif  // __CODEFILE_H__