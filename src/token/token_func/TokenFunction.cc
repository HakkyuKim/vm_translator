#include "TokenFunction.h"

TokenFunction::TokenFunction(OperationType operationType, std::string funcName,
                             std::string nLocals)
    : funcName(funcName), nLocals(nLocals), TokenFunc(operationType) {}

TokenFunction::~TokenFunction() {}