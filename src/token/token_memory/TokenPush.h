#ifndef __TOKENPUSH_H__
#define __TOKENPUSH_H__

#include "TokenMemory.h"

class TokenPush : public TokenMemory {
 public:
  TokenPush(OperationType operationType, SegmentType segmentType,
            std::string offset);
  virtual ~TokenPush();
};

#endif  // __TOKENPUSH_H__