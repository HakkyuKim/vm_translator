#ifndef __TOKENIFGOTO_H__
#define __TOKENIFGOTO_H__

#include "TokenBranch.h"

class TokenIfGoTo : public TokenBranch {
 public:
  TokenIfGoTo(OperationType operationType, std::string labelName);
  virtual ~TokenIfGoTo();
};

#endif  // __TOKENIFGOTO_H__