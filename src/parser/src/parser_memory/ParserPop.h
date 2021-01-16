#ifndef __PARSERPOP_H__
#define __PARSERPOP_H__

#include "ParserMemory.h"

class ParserPop : public ParserMemory {
 public:
  ParserPop();
  virtual ~ParserPop();
  std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) override;
};

#endif  // __PARSERPOP_H__