#ifndef __PARSERESULT_H__
#define __PARSERESULT_H__

#include <memory>

#include "TokenBase.h"

enum ParseType { UNDEFINED, WHITESPACE, CODE, COMMENT };

class ParseResult {
 public:
  ParseResult(bool success, ParseType parseType,
              std::unique_ptr<TokenBase> token);
  bool success;
  ParseType parseType;
  std::unique_ptr<TokenBase> token;
};
#endif  // __PARSERESULT_H__