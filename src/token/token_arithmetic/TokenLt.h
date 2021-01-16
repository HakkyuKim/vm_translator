#ifndef __TOKENLT_H__
#define __TOKENLT_H__

#include "TokenArithmetic.h"

class TokenLt : public TokenArithmetic {
 public:
  TokenLt(OperationType operationType);
  virtual ~TokenLt();
};

#endif  // __TOKENLT_H__