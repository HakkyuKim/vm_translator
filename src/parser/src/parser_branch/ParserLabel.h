#ifndef __PARSERLABEL_H__
#define __PARSERLABEL_H__

#include "ParserBranch.h"

class ParserLabel : public ParserBranch {
 public:
  ParserLabel();
  virtual ~ParserLabel();
  std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) override;
};

#endif  // __PARSERLABEL_H__