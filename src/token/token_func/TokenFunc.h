#ifndef __TOKENFUNC_H__
#define __TOKENFUNC_H__

#include "src/token/TokenBase.h"

class TokenFunc : public TokenBase {
 public:
  TokenFunc(OperationType operationType);
  virtual ~TokenFunc();
};

#endif  // __TOKENFUNC_H__