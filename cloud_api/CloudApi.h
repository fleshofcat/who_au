#pragma once

// TODO remove useless includes
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <future>
#include <pthread.h>
#include <vector>
#include <malloc.h>
#include <memory.h>
#include <nlohmann/json.hpp>

#include <curl/curl.h>

//#include <curlpp/cURLpp.hpp>
//#include <curlpp/Easy.hpp>
//#include <curlpp/Options.hpp>
//#include <curlpp/Exception.hpp>

using namespace std;

class CloudApi
{
    bool _isLogged = false;
    string jwtToken;

public:
    CloudApi() {}
    CloudApi(string email, string pass);

    bool isLogged();

    string authentication(string email, string pass);
    string detectImage(std::vector<char> jpegBin); // Jpeg only

private:
    static size_t WriteCallback(
            void *contents, size_t size,
            size_t nmemb, void *userp);

    void setLogged(bool logged);
    string createDemoAccount(string email, string pass);
    string login(string email, string pass);
};


