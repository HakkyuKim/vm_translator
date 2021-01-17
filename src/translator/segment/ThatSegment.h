#ifndef __THATSEGMENT_H__
#define __THATSEGMENT_H__

#include "VmSegment.h"

class ThatSegment : public VmSegment {
 public:
  ThatSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
              std::string symbol = "THAT");
  virtual ~ThatSegment();
  void Push(std::shared_ptr<StackSegment> globalStack, std::string) override;
  void Pop(std::shared_ptr<StackSegment> globalStack, std::string) override;

 private:
};

#endif  // __THATSEGMENT_H__