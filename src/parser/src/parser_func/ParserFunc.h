#ifndef __PARSERFUNC_H__
#define __PARSERFUNC_H__

#include "src/parser/src/ParserBase.h"

class ParserFunc : public ParserBase {
 public:
  ParserFunc();
  virtual ~ParserFunc();
  virtual std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) = 0;
};

#endif  // __PARSERFUNC_H__