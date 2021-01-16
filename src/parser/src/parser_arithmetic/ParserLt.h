#ifndef __PARSERLT_H__
#define __PARSERLT_H__

#include "ParserArithmetic.h"

class ParserLt : public ParserArithmetic {
 public:
  ParserLt();
  virtual ~ParserLt();
  std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) override;
};

#endif  // __PARSERLT_H__