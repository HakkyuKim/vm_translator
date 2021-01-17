#ifndef __POINTERSEGMENT_H__
#define __POINTERSEGMENT_H__

#include "VmSegment.h"

class PointerSegment : public VmSegment {
 public:
  PointerSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                 std::string symbol = "");
  virtual ~PointerSegment();

 private:
};

#endif  // __POINTERSEGMENT_H__