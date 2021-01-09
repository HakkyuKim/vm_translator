#include "CodeBlock.h"

void CodeBlock::WriteLine(std::string codeLine) 
{
    codes_.push_back(codeLine);
}

void CodeBlock::extend(CodeBlock codeBlock) 
{
    for(size_t i = 0; i< codeBlock.codes_.size(); ++i){
        codes_.push_back(codeBlock.codes_[i]);
    }
}

uint32_t CodeBlock::GetNumberOfLines() 
{
    return static_cast<uint32_t>(codes_.size());
}

std::string CodeBlock::String() 
{
    std::string asmCode = "";
    for(size_t i = 0; i < codes_.size(); ++i){
        asmCode += codes_[i] + "\n";
    }
    return asmCode;
}

void CodeBlock::ReplaceWhere(std::vector<std::string> replacements) 
{
    for(size_t i = 0; i< codes_.size(); ++i){
        if(codes_[i] == "where"){
            codes_[i] = "@" + replacements[i];
        }
    }
}

CodeBlock::CodeBlock(std::vector<std::string> codes) 
{
    codes_ = codes;
}

CodeBlock::CodeBlock(std::initializer_list<std::string> initializer) 
{
    codes_ = std::vector<std::string>(initializer);
}
