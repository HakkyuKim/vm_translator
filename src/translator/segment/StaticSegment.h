#ifndef __STATICSEGMENT_H__
#define __STATICSEGMENT_H__

#include "VmSegment.h"

class StaticSegment : public VmSegment {
 public:
  StaticSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                std::string symbol = "");
  virtual ~StaticSegment();
  void Push(std::shared_ptr<StackSegment> globalStack,
            std::string offset) override;
  void Pop(std::shared_ptr<StackSegment> globalStack,
           std::string offset) override;

  void SetFileName(std::string fileName);

 private:
  std::string fileName_;
};

#endif  // __STATICSEGMENT_H__