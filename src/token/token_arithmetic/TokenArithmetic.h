#ifndef __TOKENARITHMETIC_H__
#define __TOKENARITHMETIC_H__

#include "src/token/TokenBase.h"

class TokenArithmetic : public TokenBase {
 public:
  TokenArithmetic(OperationType operationType);
  virtual ~TokenArithmetic();
};

#endif  // __TOKENARITHMETIC_H__