#include "TokenCall.h"

TokenCall::TokenCall(OperationType operationType, std::string funcName,
                     std::string nArgs)
    : funcName(funcName), nArgs(nArgs), TokenFunc(operationType) {}

TokenCall::~TokenCall() {}