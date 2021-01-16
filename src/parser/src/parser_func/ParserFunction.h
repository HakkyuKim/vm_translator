#ifndef __PARSERFUNCTION_H__
#define __PARSERFUNCTION_H__

#include "ParserFunc.h"

class ParserFunction : public ParserFunc {
 public:
  ParserFunction();
  virtual ~ParserFunction();
  std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) override;
};

#endif  // __PARSERFUNCTION_H__