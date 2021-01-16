#ifndef __PARSERNEG_H__
#define __PARSERNEG_H__

#include "ParserArithmetic.h"

class ParserNeg : public ParserArithmetic {
 public:
  ParserNeg();
  virtual ~ParserNeg();
  std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) override;
};

#endif  // __PARSERNEG_H__