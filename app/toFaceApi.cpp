#include "toFaceApi.h"


std::string testString()
{    
//    return "Test string!";

//    return  invoke("https://backend.facecloud.tevian.ru/api/v1/users",
//                        "{\"billing_type\":\"demo\",\"data\":{\"some_data\":[\"to\",\"save\"]},"
//                        "\"email\":\"new-user@example.com\",\"password\":\"password\"}").get();

    return hard_invoke();
}


std::string hard_invoke()
{
    curlpp::Cleanup cleaner;
    curlpp::Easy request;

    request.setOpt(new curlpp::options::Url("https://backend.facecloud.tevian.ru/api/v1/users"));
    request.setOpt(new curlpp::options::Verbose(true));

    std::list<std::string> header;
    header.push_back("accept: application/json");
    header.push_back("Content-Type: application/json");

    request.setOpt(new curlpp::options::HttpHeader(header));

    std::string body = "{\"billing_type\":\"demo\",\"data\":{\"some_data\":[\"to\",\"save\"]},"
                       "\"email\":\"new-us6475837444455er@example.com\",\"password\":\"password\"}";

    request.setOpt(new curlpp::options::PostFields(body));
    request.setOpt(new curlpp::options::PostFieldSize(int(body.length())));

    std::ostringstream response;
    request.setOpt(new curlpp::options::WriteStream(&response));

    request.perform();

    return response.str();
}


std::string hard_detect_image()
{

    return "";
}






















