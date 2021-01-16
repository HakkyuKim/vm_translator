#ifndef __PARSERGOTO_H__
#define __PARSERGOTO_H__

#include "ParserBranch.h"

class ParserGoTo : public ParserBranch {
 public:
  ParserGoTo();
  virtual ~ParserGoTo();
  std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) override;
};

#endif  // __PARSERGOTO_H__