#include "DecoderCall.h"

DecoderCall::DecoderCall(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                         std::shared_ptr<DecoderState> decoderState)
    : DecoderFunc(codeBlockBuilder, decoderState) {}

DecoderCall::~DecoderCall() {}