#ifndef STACK_SEGMENT_TRANSLATOR_H_
#define STACK_SEGMENT_TRANSLATOR_H_

#include <string>

class StackSegmentTranslator {
    public:
        std::string PushFromD();
        std::string PopToD();
    private:
        std::string IncreaseSP();
        std::string DecreaseSP();
};

#endif