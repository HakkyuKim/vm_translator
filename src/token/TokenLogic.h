#ifndef __TOKENLOGIC_H__
#define __TOKENLOGIC_H__

#include "TokenBase.h"

class TokenLogic : public TokenBase {
 public:
  TokenLogic(OperationType operationType);
  virtual ~TokenLogic();
};

#endif  // __TOKENLOGIC_H__