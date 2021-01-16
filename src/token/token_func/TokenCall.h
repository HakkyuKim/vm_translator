#ifndef __TOKENCALL_H__
#define __TOKENCALL_H__

#include <string>

#include "TokenFunc.h"

class TokenCall : public TokenFunc {
 public:
  TokenCall(OperationType operationType, std::string funcName,
            std::string nLocals);
  virtual ~TokenCall();
  std::string funcName;
  std::string nLocals;
};

#endif  // __TOKENCALL_H__