#ifndef __CODEBLOCK_H__
#define __CODEBLOCK_H__

#include <string>
#include <vector>
#include <initializer_list>

class CodeBlock {
public:
  CodeBlock(){}
  CodeBlock(std::vector<std::string> codes);
  CodeBlock(std::initializer_list<std::string> initializer);
  void WriteLine(std::string codeLine);
  void extend(CodeBlock codeBlock);
  uint32_t GetNumberOfLines();
  std::string String();
  void ReplaceWhere(std::vector<std::string> replacements);
private:
  std::vector<std::string> codes_;
};

#endif // __CODEBLOCK_H__