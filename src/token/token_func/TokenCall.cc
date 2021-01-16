#include "TokenCall.h"

TokenCall::TokenCall(OperationType operationType, std::string funcName,
                     std::string nLocals)
    : funcName(funcName), nLocals(nLocals), TokenFunc(operationType) {}

TokenCall::~TokenCall() {}