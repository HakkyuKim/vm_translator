#include "DecoderAdd.h"

DecoderAdd::DecoderAdd(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                       std::shared_ptr<DecoderState> decoderState)
    : DecoderArithmetic(codeBlockBuilder, decoderState) {}

DecoderAdd::~DecoderAdd() {}