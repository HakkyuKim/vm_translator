#ifndef __TOKENPOP_H__
#define __TOKENPOP_H__

#include "TokenMemory.h"

class TokenPop : public TokenMemory {
 public:
  TokenPop(OperationType operationType, SegmentType segmentType,
           std::string offset);
  virtual ~TokenPop();
};

#endif  // __TOKENPOP_H__