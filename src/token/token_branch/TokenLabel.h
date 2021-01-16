#ifndef __TOKENLABEL_H__
#define __TOKENLABEL_H__

#include "TokenBranch.h"

class TokenLabel : public TokenBranch {
 public:
  TokenLabel(OperationType operationType, std::string labelName);
  virtual ~TokenLabel();
};

#endif  // __TOKENLABEL_H__