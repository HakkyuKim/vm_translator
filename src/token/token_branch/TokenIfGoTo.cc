#include "TokenIfGoTo.h"

TokenIfGoTo::TokenIfGoTo(OperationType operationType, std::string labelName)
    : TokenBranch(operationType, labelName) {}

TokenIfGoTo::~TokenIfGoTo() {}