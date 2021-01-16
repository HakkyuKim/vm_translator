#ifndef __TOKENBASE_H__
#define __TOKENBASE_H__

#include "OperationType.h"

class TokenBase {
 public:
  TokenBase(OperationType operationType);
  virtual ~TokenBase();
  OperationType operationType;
};

#endif  // __TOKENBASE_H__
