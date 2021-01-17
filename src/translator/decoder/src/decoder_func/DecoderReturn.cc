#include "DecoderReturn.h"

DecoderReturn::DecoderReturn(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                             std::shared_ptr<DecoderState> decoderState)
    : DecoderFunc(codeBlockBuilder, decoderState) {}

DecoderReturn::~DecoderReturn() {}