#pragma once

#include "i_user_interface.h"

#include <CloudApi.h>
#include <nlohmann/json.hpp>

//using namespace std;
//using namespace nlohmann;

class WhoAU
{
    IUserInterface *_ui;
    CloudApi cloud;

public:
    WhoAU() {}
    WhoAU(IUserInterface *ui);       // these both
    void setUi(IUserInterface * ui); // do the same

    void start();

    void authentication(
            std::string email, std::string pass);

//    std::string
//    detectFace(std::string imagePath);
};

