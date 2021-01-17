#ifndef __LOCALSEGMENT_H__
#define __LOCALSEGMENT_H__

#include "VmSegment.h"

class LocalSegment : public VmSegment {
 public:
  LocalSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
               std::string symbol = "LCL");
  virtual ~LocalSegment();

 private:
};

#endif  // __LOCALSEGMENT_H__