#ifndef __TOKENNOT_H__
#define __TOKENNOT_H__

#include "TokenLogic.h"

class TokenNot : public TokenLogic {
 public:
  TokenNot(OperationType operationType);
  virtual ~TokenNot();
};

#endif  // __TOKENNOT_H__