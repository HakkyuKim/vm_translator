#ifndef __PARSERAND_H__
#define __PARSERAND_H__

#include "ParserLogic.h"

class ParserAnd : public ParserLogic {
 public:
  ParserAnd();
  virtual ~ParserAnd();
  std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) override;
};

#endif  // __PARSERAND_H__