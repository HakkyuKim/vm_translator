#ifndef __TOKENFUNCTION_H__
#define __TOKENFUNCTION_H__

#include <string>

#include "TokenFunc.h"

class TokenFunction : public TokenFunc {
 public:
  TokenFunction(OperationType operationType, std::string funcName,
                std::string nArgs);
  virtual ~TokenFunction();
  std::string funcName;
  std::string nArgs;
};

#endif  // __TOKENFUNCTION_H__