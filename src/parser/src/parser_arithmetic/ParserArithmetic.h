#ifndef __PARSERARITHMETIC_H__
#define __PARSERARITHMETIC_H__

#include "src/parser/src/ParserBase.h"

class ParserArithmetic : public ParserBase {
 public:
  ParserArithmetic();
  virtual ~ParserArithmetic();
  virtual std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) = 0;
};

#endif  // __PARSERARITHMETIC_H__