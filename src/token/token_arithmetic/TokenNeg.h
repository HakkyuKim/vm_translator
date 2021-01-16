#ifndef __TOKENNEG_H__
#define __TOKENNEG_H__

#include "TokenArithmetic.h"

class TokenNeg : public TokenArithmetic {
 public:
  TokenNeg(OperationType operationType);
  virtual ~TokenNeg();
};

#endif  // __TOKENNEG_H__