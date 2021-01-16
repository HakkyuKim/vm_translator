#ifndef __PARSERBRANCH_H__
#define __PARSERBRANCH_H__

#include "ParserBase.h"

class ParserBranch : public ParserBase {
 public:
  ParserBranch();
  virtual ~ParserBranch();
  virtual std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) = 0;
};

#endif  // __PARSERBRANCH_H__