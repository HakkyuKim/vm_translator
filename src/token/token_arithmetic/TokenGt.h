#ifndef __TOKENGT_H__
#define __TOKENGT_H__

#include "TokenArithmetic.h"

class TokenGt : public TokenArithmetic {
 public:
  TokenGt(OperationType operationType);
  virtual ~TokenGt();
};

#endif  // __TOKENGT_H__