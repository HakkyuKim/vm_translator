#ifndef __TOKENOR_H__
#define __TOKENOR_H__

#include "TokenLogic.h"

class TokenOr : public TokenLogic {
 public:
  TokenOr(OperationType operationType);
  virtual ~TokenOr();
};

#endif  // __TOKENOR_H__