#ifndef __STACKSEGMENTTRANSLATOR_H__
#define __STACKSEGMENTTRANSLATOR_H__

#include <memory>
#include <string>

#include "src/translator/code_block/CodeBlockBuilder.h"

class StackSegment {
 public:
  StackSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder);
  void PushFromD();
  void PopToD();

 private:
  std::shared_ptr<CodeBlockBuilder> codeBlockBuilder_;
  void IncreaseSP();
  void DecreaseSP();
};

#endif  // __STACKSEGMENTTRANSLATOR_H__