#ifndef __PARSERCALL_H__
#define __PARSERCALL_H__

#include "ParserFunc.h"

class ParserCall : public ParserFunc {
 public:
  ParserCall();
  virtual ~ParserCall();
  std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) override;
};

#endif  // __PARSERCALL_H__