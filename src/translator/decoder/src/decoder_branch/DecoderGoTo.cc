#include "DecoderGoTo.h"

DecoderGoTo::DecoderGoTo(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                         std::shared_ptr<DecoderState> decoderState)
    : DecoderBranch(codeBlockBuilder, decoderState) {}

DecoderGoTo::~DecoderGoTo() {}