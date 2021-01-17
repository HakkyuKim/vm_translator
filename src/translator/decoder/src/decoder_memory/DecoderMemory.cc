#include "DecoderMemory.h"

DecoderMemory::DecoderMemory(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                             std::shared_ptr<DecoderState> decoderState)
    : DecoderBase(codeBlockBuilder, decoderState) {}

DecoderMemory::~DecoderMemory() {}