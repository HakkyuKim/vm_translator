#ifndef __TOKENBASE_H__
#define __TOKENBASE_H__

#include "src/type/OperationType.h"

class TokenBase {
 public:
  TokenBase(OperationType operationType);
  virtual ~TokenBase();
  OperationType operationType;
};

#endif  // __TOKENBASE_H__
