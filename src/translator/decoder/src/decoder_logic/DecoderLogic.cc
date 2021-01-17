#include "DecoderLogic.h"

DecoderLogic::DecoderLogic(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                           std::shared_ptr<DecoderState> decoderState)
    : DecoderBase(codeBlockBuilder, decoderState) {}

DecoderLogic::~DecoderLogic() {}