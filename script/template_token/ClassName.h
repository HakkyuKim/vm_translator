#ifndef __{%DERIVEDCLASS_HEADER%}_H__
#define __{%DERIVEDCLASS_HEADER%}_H__

{%BASECLASS_HEADER%}
#include "OperationType.h"

class {%DERIVEDCLASS%}{%BASECLASS_INHERITANCE%} {
public:
    {%DERIVEDCLASS%}(OperationType operationType);
    virtual ~{%DERIVEDCLASS%}();
};

#endif // __{%DERIVEDCLASS_HEADER%}_H__