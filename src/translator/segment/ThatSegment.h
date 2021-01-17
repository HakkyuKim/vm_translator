#ifndef __THATSEGMENT_H__
#define __THATSEGMENT_H__

#include "VmSegment.h"

class ThatSegment : public VmSegment {
 public:
  ThatSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
              std::string symbol = "THAT");
  virtual ~ThatSegment();

 private:
};

#endif  // __THATSEGMENT_H__