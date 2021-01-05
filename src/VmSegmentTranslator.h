#ifndef VM_SEGMENT_TRANSLATOR_H_
#define VM_SEGMENT_TRANSLATOR_H_

#include <string>

class VmSegmentTranslator {
    public:
        VmSegmentTranslator(){}
        VmSegmentTranslator(std::string symbol)
        :baseAddrPointerSymbol_(symbol){}
        std::string PutFromD();
        std::string PutToD(std::string index);
        std::string SetLocationOverwrite(std::string index);
    private:
        std::string SetLocation(std::string index);
        std::string baseAddrPointerSymbol_;
};

#endif