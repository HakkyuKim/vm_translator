#ifndef __TOKENADD_H__
#define __TOKENADD_H__

#include "TokenArithmetic.h"

class TokenAdd : public TokenArithmetic {
 public:
  TokenAdd(OperationType operationType);
  virtual ~TokenAdd();
};

#endif  // __TOKENADD_H__