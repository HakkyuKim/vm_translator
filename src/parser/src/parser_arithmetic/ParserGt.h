#ifndef __PARSERGT_H__
#define __PARSERGT_H__

#include "ParserArithmetic.h"

class ParserGt : public ParserArithmetic {
 public:
  ParserGt();
  virtual ~ParserGt();
  std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) override;
};

#endif  // __PARSERGT_H__