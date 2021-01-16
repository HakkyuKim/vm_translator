#ifndef __{%DERIVEDCLASS_HEADER%}_H__
#define __{%DERIVEDCLASS_HEADER%}_H__

{%BASECLASS_HEADER%}
#include "CodeBuilder.h"

class {%DERIVEDCLASS%}{%BASECLASS_INHERITANCE%} {
public:
    {%DERIVEDCLASS%}(CodeBuilder codeBuilder);
    virtual ~{%DERIVEDCLASS%}();
private:
};

#endif // __{%DERIVEDCLASS_HEADER%}_H__