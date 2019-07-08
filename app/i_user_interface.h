#pragma once

class IUserInterface
{
public:
    virtual ~IUserInterface();
    virtual void requireAuth() = 0;
    virtual void letUserWork() = 0;
};




