#include "TokenBranch.h"

TokenBranch::TokenBranch(OperationType operationType, std ::string labelName)
    : labelName(labelName), TokenBase(operationType) {}

TokenBranch::~TokenBranch() {}