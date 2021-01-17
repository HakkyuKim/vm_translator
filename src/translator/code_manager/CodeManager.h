#ifndef __CODEMANAGER_H__
#define __CODEMANAGER_H__

#include <map>
#include <string>

#include "CodeFile.h"

class CodeManager {
 public:
  void CreateCodeFile(std::string fileName);
  void AddCodeToCodeFile(std::string fileName,
                         std::unique_ptr<CodeBlock> codeBlock);
  void AddCodeToCodeFunction(std::string fileName, std::string funcName,
                             std::unique_ptr<CodeBlock> codeBlock);
  CodeBlock* Merge();

 private:
  std::map<std::string, std::unique_ptr<CodeFile>> codeFiles_;
};

#endif  // __CODEMANAGER_H__