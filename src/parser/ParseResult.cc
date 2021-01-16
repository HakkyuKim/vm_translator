#include "ParseResult.h"

ParseResult::ParseResult(bool success, ParseType parseType,
                         std::unique_ptr<TokenBase> token)
    : success(success), parseType(parseType), token(std::move(token)) {}
