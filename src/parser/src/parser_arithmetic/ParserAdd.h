#ifndef __PARSERADD_H__
#define __PARSERADD_H__

#include "ParserArithmetic.h"

class ParserAdd : public ParserArithmetic {
 public:
  ParserAdd();
  virtual ~ParserAdd();
  std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) override;
};

#endif  // __PARSERADD_H__