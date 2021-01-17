#ifndef __THISSEGMENT_H__
#define __THISSEGMENT_H__

#include "VmSegment.h"

class ThisSegment : public VmSegment {
 public:
  ThisSegment(std::shared_ptr<CodeBlockBuilder> CodeBlockBuilder,
              std::string symbol = "THIS");
  virtual ~ThisSegment();
  virtual void Push(std::shared_ptr<StackSegment> globalStack, std::string);
  virtual void Pop(std::shared_ptr<StackSegment> globalStack, std::string);

 private:
};

#endif  // __THISSEGMENT_H__