#ifndef __{%DERIVEDCLASS_HEADER%}_H__
#define __{%DERIVEDCLASS_HEADER%}_H__

{%BASECLASS_HEADER%}

class {%DERIVEDCLASS%}{%BASECLASS_INHERITANCE%} {
public:
    {%DERIVEDCLASS%}();
    virtual ~{%DERIVEDCLASS%}();
    virtual TokenBase parse(std::vector<std::string> stringTokens);
};

#endif // __{%DERIVEDCLASS_HEADER%}_H__