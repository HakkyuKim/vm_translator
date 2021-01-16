#include "TokenFunction.h"

TokenFunction::TokenFunction(OperationType operationType, std::string funcName,
                             std::string nArgs)
    : funcName(funcName), nArgs(nArgs), TokenFunc(operationType) {}

TokenFunction::~TokenFunction() {}