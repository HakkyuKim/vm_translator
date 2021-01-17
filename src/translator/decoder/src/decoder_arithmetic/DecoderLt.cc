#include "DecoderLt.h"

DecoderLt::DecoderLt(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                     std::shared_ptr<DecoderState> decoderState)
    : DecoderArithmetic(codeBlockBuilder, decoderState) {}

DecoderLt::~DecoderLt() {}