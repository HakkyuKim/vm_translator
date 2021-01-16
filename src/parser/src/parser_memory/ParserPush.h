#ifndef __PARSERPUSH_H__
#define __PARSERPUSH_H__

#include "ParserMemory.h"

class ParserPush : public ParserMemory {
 public:
  ParserPush();
  virtual ~ParserPush();
  std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) override;
};

#endif  // __PARSERPUSH_H__