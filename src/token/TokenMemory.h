#ifndef __TOKENMEMORY_H__
#define __TOKENMEMORY_H__

#include <string>

#include "SegmentType.h"
#include "TokenBase.h"

class TokenMemory : public TokenBase {
 public:
  TokenMemory(OperationType operationType, SegmentType segmentType,
              std::string offset);
  virtual ~TokenMemory();
  SegmentType segmentType;
  std::string offset;
};

#endif  // __TOKENMEMORY_H__