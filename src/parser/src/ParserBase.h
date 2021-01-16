#ifndef __PARSERBASE_H__
#define __PARSERBASE_H__

#include <memory>
#include <string>
#include <vector>

#include "../token/TokenBase.h"

class ParserBase {
 public:
  ParserBase();
  virtual ~ParserBase();
  virtual std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) = 0;
};

#endif  // __PARSERBASE_H__