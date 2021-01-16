#include "TokenPush.h"

TokenPush::TokenPush(OperationType operationType, SegmentType segmentType,
                     std::string offset)
    : TokenMemory(operationType, segmentType, offset) {}

TokenPush::~TokenPush() {}