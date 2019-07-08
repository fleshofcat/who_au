#pragma once

// TODO remove useless includes
#include <cstdlib>
#include <sstream>
#include <future>
#include <pthread.h>
#include <vector>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

class CloudApi
{
public:
    static std::string getTestString();

    static std::string
    createDemoAccount(std::string email, std::string pass);


    static std::string
    login(std::string email, std::string pass);

    static std::string
    detectImage(std::vector<char> imageBin); // Jpeg
};


