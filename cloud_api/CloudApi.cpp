#include "CloudApi.h"


CloudApi::CloudApi(string email, string pass)
{
    authentication(email, pass);
}


bool CloudApi::isLogged()
{
    return _isLogged;
}


void CloudApi::setLogged(bool logged)
{
    _isLogged = logged;
}


string CloudApi::authentication(string email, string pass)
{
    nlohmann::json loginResult =
            nlohmann::json::parse(login(email, pass));


    if (loginResult["status_code"] == 200) // success
    {
        setLogged(true);
        jwtToken = loginResult["data"]["access_token"];
        return loginResult.dump();
    }
    else if (loginResult["status_code"] == 401) // invalid email/pass
    {
        nlohmann::json createResult;
        createResult = nlohmann::json::parse(
                    createDemoAccount(email, pass));

        if (createResult["status_code"] == 201) // account create success
        {
            return authentication(email, pass);
        }
    }

    return loginResult.dump();
}


std::string CloudApi::
detectImage(std::vector<char> jpegBin)
{
    if (!isLogged())
    {
        return "{\"message\": \"authorization with token required\","
               "\"status_code\": 401}";
    }

    CURLcode ret;
    CURL *curl;
    struct curl_slist *headers;

    std::string response;

    headers = nullptr;
    headers = curl_slist_append(headers, "accept: application/json");
    headers = curl_slist_append(
                headers, string("Authorization: Bearer " + jwtToken).c_str());
    headers = curl_slist_append(headers, "Content-Type: image/jpeg");

    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL,
                     "https://backend.facecloud.tevian.ru"
                     "/api/v1/detect?fd_min_size=0&fd_max_size=0"
                     "&fd_threshold=0.8&demographics=true"
                     "&attributes=true&landmarks=false");

    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jpegBin.data());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE_LARGE, jpegBin.size());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);


    ret = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);

    return  response;
}

size_t CloudApi::
WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
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
login(std::string email, std::string pass)
{
    CURLcode ret;
    CURL *curl;
    struct curl_slist *headers;

    std::string response;

    headers = nullptr;
    headers = curl_slist_append(headers, "accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "https://"
                                        "backend.facecloud.tevian.ru"
                                        "/api/v1/login");

    std::string body = "{\"email\":\"" + email
            + "\",\"password\":\"" + pass + "\"}";

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












