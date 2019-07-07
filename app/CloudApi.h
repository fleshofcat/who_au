#pragma once

#include <cstdlib>
#include <sstream>
#include <future>
#include <pthread.h>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

class CloudApi
{
public:
    static std::string getTestString();

    static std::string createNewUser_hard();
    static std::string detectImage_hard();
    static std::string detectImage_curl_hard();
};


