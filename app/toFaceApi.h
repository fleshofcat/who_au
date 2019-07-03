#pragma once

#include <cstdlib>
#include <sstream>
#include <future>
//#include <thread>
#include <pthread.h>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

//#include <string>
//#include <iostream>

std::string testString();

std::future<std::string>
invoke(std::string const& url,
       std::string const& body);
std::string hard_invoke();
std::string hard_detect_image();
