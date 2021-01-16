#ifndef __PARSERNOT_H__
#define __PARSERNOT_H__

#include "ParserLogic.h"

class ParserNot : public ParserLogic {
 public:
  ParserNot();
  virtual ~ParserNot();
  std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) override;
};

#endif  // __PARSERNOT_H__