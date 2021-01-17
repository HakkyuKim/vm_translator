#include "DecoderIfGoTo.h"

DecoderIfGoTo::DecoderIfGoTo(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                             std::shared_ptr<DecoderState> decoderState)
    : DecoderBranch(codeBlockBuilder, decoderState) {}

DecoderIfGoTo::~DecoderIfGoTo() {}