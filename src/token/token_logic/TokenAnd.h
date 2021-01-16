#ifndef __TOKENAND_H__
#define __TOKENAND_H__

#include "TokenLogic.h"

class TokenAnd : public TokenLogic {
 public:
  TokenAnd(OperationType operationType);
  virtual ~TokenAnd();
};

#endif  // __TOKENAND_H__