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
    createUser(std::string email, std::string pass);

    static std::string
    loginUser(std::string email, std::string pass);

    static std::string
    detectImage_hard(std::string imagePath);

    static std::string
    detectImage_ByImage(std::vector<char> imageBin); // Jpeg
};


