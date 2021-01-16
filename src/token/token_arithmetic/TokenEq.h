#ifndef __TOKENEQ_H__
#define __TOKENEQ_H__

#include "TokenArithmetic.h"

class TokenEq : public TokenArithmetic {
 public:
  TokenEq(OperationType operationType);
  virtual ~TokenEq();
};

#endif  // __TOKENEQ_H__