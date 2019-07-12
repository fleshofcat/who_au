#pragma once

#include "i_user_interface.h"

#include <list>
#include <fstream>

#include <CloudApi.h>
#include <nlohmann/json.hpp>

//using namespace std;
//using namespace nlohmann;

class WhoAU
{
    IUserInterface *ui;
    CloudApi cloud;

    class MapWithContains : public std::map<string, string>
    {
    public:
        bool contains(string key)
        {
            return find(key) != end() ? true : false;
        }
    } loadedFiles;

public:
    WhoAU() {}
    WhoAU(IUserInterface *ui);       // these both
    void setUi(IUserInterface * ui); // do the same

    void start();
    void authentication(
            std::string email, std::string pass);

    void detectFace(std::list<std::string> imagePaths);

private:
    std::string sendFile(string imagePath); // TODO add extensions converting
};

