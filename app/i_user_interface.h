#pragma once

#include <string>

class IUserInterface
{
public:
//    virtual ~IUserInterface();
    virtual void requireAuth() = 0;
    virtual void errWhenAuth(std::string errMsg) = 0;
    virtual void requireUserWork() = 0;
};

//IUserInterface::~IUserInterface(){}



