#ifndef __POINTERSEGMENTTRANSLATOR_H__
#define __POINTERSEGMENTTRANSLATOR_H__

#include "VmSegmentTranslator.h"

class PointerSegmentTranslator : public VmSegmentTranslator{
public:
    PointerSegmentTranslator()
    :VmSegmentTranslator(""){}
    CodeBlock CopyFromD(std::string address, std::string index) override;
    CodeBlock CopyToD(std::string address, std::string index) override;
    CodeBlock CalculateAddress(std::string address, std::string index) override;
private:
    std::string symbolThisThat_;
};

#endif // __POINTERSEGMENTTRANSLATOR_H__