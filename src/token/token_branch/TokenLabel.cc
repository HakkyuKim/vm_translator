#include "TokenLabel.h"

TokenLabel::TokenLabel(OperationType operationType, std::string labelName)
    : TokenBranch(operationType, labelName) {}

TokenLabel::~TokenLabel() {}