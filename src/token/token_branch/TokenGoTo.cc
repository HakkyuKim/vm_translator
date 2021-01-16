#include "TokenGoTo.h"

TokenGoTo::TokenGoTo(OperationType operationType, std::string labelName)
    : TokenBranch(operationType, labelName) {}

TokenGoTo::~TokenGoTo() {}