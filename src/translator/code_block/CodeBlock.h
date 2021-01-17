#ifndef __CODEBLOCK_H__
#define __CODEBLOCK_H__

#include <initializer_list>
#include <string>
#include <vector>

class CodeBlockBuilder;

class CodeBlock {
 public:
  CodeBlock() {}
  CodeBlock(std::vector<std::string> codes);
  CodeBlock(std::initializer_list<std::string> initializer);
  void WriteLine(std::string codeLine);
  void extend(CodeBlock codeBlock);
  uint32_t GetNumberOfLines();
  std::string String();
  void ReplaceWhere(std::vector<std::string> replacements);

  static CodeBlockBuilder Create();
  friend CodeBlockBuilder;

 private:
  std::vector<std::string> codes_;
};

#endif  // __CODEBLOCK_H__