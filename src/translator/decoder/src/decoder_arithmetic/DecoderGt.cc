#include "DecoderGt.h"

DecoderGt::DecoderGt(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                     std::shared_ptr<DecoderState> decoderState)
    : DecoderArithmetic(codeBlockBuilder, decoderState) {}

DecoderGt::~DecoderGt() {}