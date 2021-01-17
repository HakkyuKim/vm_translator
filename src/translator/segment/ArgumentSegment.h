#ifndef __ARGUMENTSEGMENT_H__
#define __ARGUMENTSEGMENT_H__

#include "VmSegment.h"

class ArgumentSegment : public VmSegment {
 public:
  ArgumentSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                  std::string symbol = "ARG");
  virtual ~ArgumentSegment();

 private:
};

#endif  // __ARGUMENTSEGMENT_H__