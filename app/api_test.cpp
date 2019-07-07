#include "api_test.h"
//#include "toFaceApi.h"

int main()
{
//    std::cout << getTestString() << std::endl;
    createNewUser_hard();
    return 0;
}

std::string createNewUser_hard()
{
    curlpp::Cleanup cleaner;
    curlpp::Easy request;

    request.setOpt(new curlpp::options::Url("https://backend.facecloud.tevian.ru/api/v1/users"));
    request.setOpt(new curlpp::options::Verbose(true));

    std::list<std::string> header;
    header.push_back("accept: application/json");
    header.push_back("Content-Type: application/json");

    request.setOpt(new curlpp::options::HttpHeader(header));

    std::string body = "{\"billing_type\":\"demo\",\"email\":\"new-us6475835444844r4rdccfd455er@example.com\",\"password\":\"password\"}";

    request.setOpt(new curlpp::options::PostFields(body));
    request.setOpt(new curlpp::options::PostFieldSize(int(body.length())));

    std::ostringstream response;
//    request.setOpt(new curlpp::options::WriteStream(&response));

    request.perform();
//response.fail();
//    return response.str();
    return "";
}


std::string detectImage_curl_hard()
{
    CURLcode ret;
    CURL *curl;
    struct curl_slist *headers;

    headers = nullptr;
    headers = curl_slist_append(headers, "accept: application/json");
    headers = curl_slist_append(headers, "Authorization: Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJqdGkiOiIyOTcyMDg2NC1jZDg5LTQ3MGEtYWUzYS1mOWYzOWY1OWNiODYiLCJzdWIiOjM2LCJpYXQiOjE1NjIxNzg0NjYsIm5iZiI6MTU2MjE3ODQ2NiwidHlwZSI6ImFjY2VzcyIsImZyZXNoIjpmYWxzZX0.TSwvRkY0cIOHNU-copIcfWiDdia7EnEoq1MD51i2jG8");
    headers = curl_slist_append(headers, "Content-Type: image/jpeg");


    FILE *file = fopen("/home/kat/Desktop/face.jpg", "rb");
    fseek(file, 0L, SEEK_END);
    size_t file_size = size_t(ftell(file));
    fseek(file, 0L, SEEK_SET);
    char *image_buff = new char[file_size];

    fread(image_buff, 1, file_size, file);

    curl = curl_easy_init();
    //    curl_easy_setopt(curl, CURLOPT_BUFFERSIZE, 102400L);
    curl_easy_setopt(curl, CURLOPT_URL, "https://backend.facecloud.tevian.ru/api/v1/detect?fd_min_size=0&fd_max_size=0&fd_threshold=0.8&demographics=true&attributes=true&landmarks=false");
    //    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);

    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, image_buff);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE_LARGE, curl_off_t(file_size));
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    //    curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.65.1");
    //    curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
    //    curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, long(CURL_HTTP_VERSION_2TLS));
    //    curl_easy_setopt(curl, CURLOPT_HTTP09_ALLOWED, 1L);
    //    curl_easy_setopt(curl, CURLOPT_SSH_KNOWNHOSTS, "/home/kat/.ssh/known_hosts");
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");

    ret = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    curl = nullptr;
    curl_slist_free_all(headers);
    headers = nullptr;

    fclose(file);

    return "";
}


std::string detectImage_hard()
{
    try
    {
        curlpp::Cleanup cleaner;
        curlpp::Easy request;

        request.setOpt(new curlpp::options::Url("https://backend.facecloud.tevian.ru/api/v1/detect?fd_min_size=0&fd_max_size=0&fd_threshold=0.8"));
        request.setOpt(new curlpp::options::Verbose(true));

        std::list<std::string> header;
        //    header.push_back("Content-Type: multipart/form-data");
        //        header.push_back("Accept: application/json");
        header.push_back("Content-Type: image/jpeg");
        header.push_back("Authorization: Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJqdGkiOiIyOTcyMDg2NC1jZDg5LTQ3MGEtYWUzYS1mOWYzOWY1OWNiODYiLCJzdWIiOjM2LCJpYXQiOjE1NjIxNzg0NjYsIm5iZiI6MTU2MjE3ODQ2NiwidHlwZSI6ImFjY2VzcyIsImZyZXNoIjpmYWxzZX0.TSwvRkY0cIOHNU-copIcfWiDdia7EnEoq1MD51i2jG8");
        //    header.push_back("content-type: multipart/form-data; boundary=----WebKitFormBoundary7MA4YWxkTrZu0gW");

        FILE *file = fopen("/home/kat/Desktop/face.jpg", "rb");

        request.setOpt(new curlpp::options::HttpHeader(header));
        request.setOpt(new curlpp::options::ReadFile(file));
        //        request.setOpt()

        //        std::ostringstream response; // reaponse
        //        request.setOpt(new curlpp::options::WriteStream(&response));

        request.perform();
    }
    catch ( curlpp::LogicError & e ) {
        std::cout << e.what() << std::endl;
    }
    catch ( curlpp::RuntimeError & e ) {
        std::cout << e.what() << std::endl;
    }

    return "";
}

