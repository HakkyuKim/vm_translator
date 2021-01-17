#ifndef __TEMPSEGMENT_H__
#define __TEMPSEGMENT_H__

#include "VmSegment.h"

class TempSegment : public VmSegment {
 public:
  TempSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
              std::string symbol = "");
  virtual ~TempSegment();
  void Push(std::shared_ptr<StackSegment> globalStack,
            std::string offset) override;
  void Pop(std::shared_ptr<StackSegment> globalStack,
           std::string offset) override;

 private:
};

#endif  // __TEMPSEGMENT_H__