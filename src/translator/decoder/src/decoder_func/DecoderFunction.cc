#include "DecoderFunction.h"

DecoderFunction::DecoderFunction(
    std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
    std::shared_ptr<DecoderState> decoderState)
    : DecoderFunc(codeBlockBuilder, decoderState) {}

DecoderFunction::~DecoderFunction() {}