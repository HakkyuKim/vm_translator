#include "DecoderFunc.h"

DecoderFunc::DecoderFunc(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                         std::shared_ptr<DecoderState> decoderState)
    : DecoderBase(codeBlockBuilder, decoderState) {}

DecoderFunc::~DecoderFunc() {}