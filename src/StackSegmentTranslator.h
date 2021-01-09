#ifndef __STACKSEGMENTTRANSLATOR_H__
#define __STACKSEGMENTTRANSLATOR_H__

#include <string>
#include "CodeBlock.h"

class StackSegmentTranslator {
    public:
        CodeBlock PushFromD();
        CodeBlock PopToD();
    private:
        CodeBlock IncreaseSP();
        CodeBlock DecreaseSP();
};


#endif // __STACKSEGMENTTRANSLATOR_H__