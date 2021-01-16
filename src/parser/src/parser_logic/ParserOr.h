#ifndef __PARSEROR_H__
#define __PARSEROR_H__

#include "ParserLogic.h"

class ParserOr : public ParserLogic {
 public:
  ParserOr();
  virtual ~ParserOr();
  std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) override;
};

#endif  // __PARSEROR_H__