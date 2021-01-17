#include "DecoderBranch.h"

DecoderBranch::DecoderBranch(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                             std::shared_ptr<DecoderState> decoderState)
    : DecoderBase(codeBlockBuilder, decoderState) {}

DecoderBranch::~DecoderBranch() {}