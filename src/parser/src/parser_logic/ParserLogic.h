#ifndef __PARSERLOGIC_H__
#define __PARSERLOGIC_H__

#include "src/parser/src/ParserBase.h"

class ParserLogic : public ParserBase {
 public:
  ParserLogic();
  virtual ~ParserLogic();
  virtual std::unique_ptr<TokenBase> parse(
      std::vector<std::string> stringTokens) = 0;
};

#endif  // __PARSERLOGIC_H__