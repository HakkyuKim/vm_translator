#ifndef __TOKENCALL_H__
#define __TOKENCALL_H__

#include <string>

#include "TokenFunc.h"

class TokenCall : public TokenFunc {
 public:
  TokenCall(OperationType operationType, std::string funcName,
            std::string nArgs);
  virtual ~TokenCall();
  std::string funcName;
  std::string nArgs;
};

#endif  // __TOKENCALL_H__