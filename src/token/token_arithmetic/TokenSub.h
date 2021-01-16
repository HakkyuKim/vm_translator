#ifndef __TOKENSUB_H__
#define __TOKENSUB_H__

#include "TokenArithmetic.h"

class TokenSub : public TokenArithmetic {
 public:
  TokenSub(OperationType operationType);
  virtual ~TokenSub();
};

#endif  // __TOKENSUB_H__