#ifndef __PARSERRETURN_H__
#define __PARSERRETURN_H__

#include "ParserFunc.h"

class ParserReturn : public ParserFunc {
 public:
  ParserReturn();
  virtual ~ParserReturn();
  std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) override;
};

#endif  // __PARSERRETURN_H__