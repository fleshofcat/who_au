#pragma once

#include <string>
#include <utility>
#include <map>

class IUserInterface
{
public:
//    virtual ~IUserInterface();
    virtual void showAuth() = 0;
    virtual void showAuthError(std::string errMsg) = 0;
    virtual void showUserWorkspace() = 0;
    virtual void showCurrentResult(
            std::map<std::string,   // file name
            std::string>            // json report. Empty when
            loadedFilesInfo) = 0;   // file is unhandled

    virtual void showDetectionError(std::string msg) = 0;
};

//IUserInterface::~IUserInterface(){}



