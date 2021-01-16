#include "TokenMemory.h"

TokenMemory::TokenMemory(OperationType operationType, SegmentType segmentType,
                         std::string offset)
    : segmentType(segmentType), offset(offset), TokenBase(operationType) {}

TokenMemory::~TokenMemory() {}