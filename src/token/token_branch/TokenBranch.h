#ifndef __TOKENBRANCH_H__
#define __TOKENBRANCH_H__

#include <string>

#include "src/token/TokenBase.h"

class TokenBranch : public TokenBase {
 public:
  TokenBranch(OperationType operationType, std::string labelName);
  virtual ~TokenBranch();
  std::string labelName;
};

#endif  // __TOKENBRANCH_H__