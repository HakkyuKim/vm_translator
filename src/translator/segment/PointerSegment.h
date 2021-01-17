#ifndef __POINTERSEGMENT_H__
#define __POINTERSEGMENT_H__

#include "ThatSegment.h"

class PointerSegment : public VmSegment {
 public:
  PointerSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                 std::string symbol = "");
  virtual ~PointerSegment();

  void Push(std::shared_ptr<StackSegment> globalStack,
            std::string zeroOrOne) override;
  void Pop(std::shared_ptr<StackSegment> globalStack,
           std::string zeroOrOne) override;

 private:
};

#endif  // __POINTERSEGMENT_H__