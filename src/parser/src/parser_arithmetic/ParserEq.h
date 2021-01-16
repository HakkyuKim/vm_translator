#ifndef __PARSEREQ_H__
#define __PARSEREQ_H__

#include "ParserArithmetic.h"

class ParserEq : public ParserArithmetic {
 public:
  ParserEq();
  virtual ~ParserEq();
  std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) override;
};

#endif  // __PARSEREQ_H__