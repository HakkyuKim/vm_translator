#ifndef __CONSTANTSEGMENT_H__
#define __CONSTANTSEGMENT_H__

#include "VmSegment.h"

class ConstantSegment : public VmSegment {
 public:
  ConstantSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                  std::string symbol = "");
  virtual ~ConstantSegment();

  void Push(std::shared_ptr<StackSegment> globalStack,
            std::string val) override;
  void Pop(std::shared_ptr<StackSegment> globalStack, std::string) override;

 private:
};

#endif  // __CONSTANTSEGMENT_H__