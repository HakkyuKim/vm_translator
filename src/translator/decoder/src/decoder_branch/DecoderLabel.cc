#include "DecoderLabel.h"

DecoderLabel::DecoderLabel(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                           std::shared_ptr<DecoderState> decoderState)
    : DecoderBranch(codeBlockBuilder, decoderState) {}

DecoderLabel::~DecoderLabel() {}