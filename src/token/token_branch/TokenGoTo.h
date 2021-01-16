#ifndef __TOKENGOTO_H__
#define __TOKENGOTO_H__

#include "TokenBranch.h"

class TokenGoTo : public TokenBranch {
 public:
  TokenGoTo(OperationType operationType, std::string labelName);
  virtual ~TokenGoTo();
};

#endif  // __TOKENGOTO_H__