#ifndef __PARSERMEMORY_H__
#define __PARSERMEMORY_H__

#include "src/parser/src/ParserBase.h"

class ParserMemory : public ParserBase {
 public:
  ParserMemory();
  virtual ~ParserMemory();
  virtual std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) = 0;
};

#endif  // __PARSERMEMORY_H__