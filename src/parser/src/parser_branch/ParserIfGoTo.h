#ifndef __PARSERIFGOTO_H__
#define __PARSERIFGOTO_H__

#include "ParserBranch.h"

class ParserIfGoTo : public ParserBranch {
 public:
  ParserIfGoTo();
  virtual ~ParserIfGoTo();
  std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) override;
};

#endif  // __PARSERIFGOTO_H__