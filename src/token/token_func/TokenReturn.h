#ifndef __TOKENRETURN_H__
#define __TOKENRETURN_H__

#include "TokenFunc.h"

class TokenReturn : public TokenFunc {
 public:
  TokenReturn(OperationType operationType);
  virtual ~TokenReturn();
};

#endif  // __TOKENRETURN_H__