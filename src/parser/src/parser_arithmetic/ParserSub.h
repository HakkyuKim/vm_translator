#ifndef __PARSERSUB_H__
#define __PARSERSUB_H__

#include "ParserArithmetic.h"

class ParserSub : public ParserArithmetic {
 public:
  ParserSub();
  virtual ~ParserSub();
  std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) override;
};

#endif  // __PARSERSUB_H__