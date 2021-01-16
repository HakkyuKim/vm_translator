#include "TokenPop.h"

TokenPop::TokenPop(OperationType operationType, SegmentType segmentType,
                   std::string offset)
    : TokenMemory(operationType, segmentType, offset) {}

TokenPop::~TokenPop() {}