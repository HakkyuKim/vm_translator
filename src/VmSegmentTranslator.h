#ifndef __VMSEGMENTTRANSLATOR_H__
#define __VMSEGMENTTRANSLATOR_H__


#include <string>
#include "CodeBlock.h"

class VmSegmentTranslator {
    public:
        VmSegmentTranslator(){}
        VmSegmentTranslator(std::string symbol)
        :baseAddrPointerSymbol_(symbol){}
        virtual CodeBlock CopyFromD(std::string address, std::string index);
        virtual CodeBlock CopyToD(std::string address, std::string index);
        virtual CodeBlock CalculateAddress(std::string address, std::string index);
    private:
        std::string baseAddrPointerSymbol_;
};


#endif // __VMSEGMENTTRANSLATOR_H__