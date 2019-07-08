#include "CloudApi.h"
#include <malloc.h>
#include <memory.h>

std::string getTestString()
{    
    return "tst str";
}

std::string CloudApi::login(std::string /*email*/, std::string /*pass*/)
{
    return "";
}

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


std::string CloudApi::createDemoAccount(std::string email, std::string pass)
{
    CURLcode ret;
    CURL *curl;
    struct curl_slist *headers;

    std::string response;

    headers = nullptr;
    headers = curl_slist_append(headers, "accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "https://backend.facecloud.tevian.ru/api/v1/users");

    std::string body = "{\"billing_type\":\"demo\",\"email\":\""
            + email + "\",\"password\":\"" + pass + "\"}";

    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE_LARGE, curl_off_t(body.size()));
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);


    ret = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);

    return  response;
}

std::string CloudApi::
detectImage(std::vector<char> imageBin)
{
    CURLcode ret;
    CURL *curl;
    struct curl_slist *headers;

    std::string response;

    headers = nullptr;
    headers = curl_slist_append(headers, "accept: application/json");
    headers = curl_slist_append(headers, "Authorization: Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJqdGkiOiIyOTcyMDg2NC1jZDg5LTQ3MGEtYWUzYS1mOWYzOWY1OWNiODYiLCJzdWIiOjM2LCJpYXQiOjE1NjIxNzg0NjYsIm5iZiI6MTU2MjE3ODQ2NiwidHlwZSI6ImFjY2VzcyIsImZyZXNoIjpmYWxzZX0.TSwvRkY0cIOHNU-copIcfWiDdia7EnEoq1MD51i2jG8");
    headers = curl_slist_append(headers, "Content-Type: image/jpeg");

    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "https://backend.facecloud.tevian.ru/api/v1/detect?fd_min_size=0&fd_max_size=0&fd_threshold=0.8&demographics=true&attributes=true&landmarks=false");

    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, imageBin.data());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE_LARGE, curl_off_t(imageBin.size()));
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);


    ret = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    curl = nullptr;
    curl_slist_free_all(headers);
    headers = nullptr;

    return  response;
}












