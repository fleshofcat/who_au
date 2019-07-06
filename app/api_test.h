#pragma once

#include <cstdlib>
#include <sstream>
#include <future>
#include <pthread.h>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

std::string createNewUser_hard();
std::string detectImage_hard();
std::string detectImage_curl_hard();

