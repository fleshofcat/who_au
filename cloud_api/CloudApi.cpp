#include "CloudApi.h"
#include <malloc.h>
#include <memory.h>

std::string getTestString()
{    
    return "tst str";
}

std::string
CloudApi::createUser(std::string /*email*/, std::string /*pass*/)
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

std::string CloudApi::loginUser(std::string /*email*/, std::string /*pass*/)
{
    return "";
}

struct string {
  char *ptr;
  size_t len;
};

void init_string(struct string *s) {
  s->len = 0;
  s->ptr = static_cast<char*>(malloc(s->len+1));
  if (s->ptr == nullptr) {
    fprintf(stderr, "malloc() failed\n");
    exit(EXIT_FAILURE);
  }
  s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s)
{
  size_t new_len = s->len + size*nmemb;
  s->ptr = static_cast<char*>(realloc(s->ptr, new_len+1));
  if (s->ptr == nullptr) {
    fprintf(stderr, "realloc() failed\n");
    exit(EXIT_FAILURE);
  }
  memcpy(s->ptr+s->len, ptr, size*nmemb);
  s->ptr[new_len] = '\0';
  s->len = new_len;

  return size*nmemb;
}


std::string
CloudApi::detectImage_hard(std::string imagePath)
{
    CURLcode ret;
    CURL *curl;
    struct curl_slist *headers;
    struct string response;
    init_string(&response);

    headers = nullptr;
    headers = curl_slist_append(headers, "accept: application/json");
    headers = curl_slist_append(headers, "Authorization: Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJqdGkiOiIyOTcyMDg2NC1jZDg5LTQ3MGEtYWUzYS1mOWYzOWY1OWNiODYiLCJzdWIiOjM2LCJpYXQiOjE1NjIxNzg0NjYsIm5iZiI6MTU2MjE3ODQ2NiwidHlwZSI6ImFjY2VzcyIsImZyZXNoIjpmYWxzZX0.TSwvRkY0cIOHNU-copIcfWiDdia7EnEoq1MD51i2jG8");
    headers = curl_slist_append(headers, "Content-Type: image/jpeg");


//    FILE *file = fopen("/home/kat/Desktop/face.jpg", "rb");
    FILE *file = fopen(imagePath.c_str(), "rb");
    fseek(file, 0L, SEEK_END);
    size_t file_size = size_t(ftell(file));
    fseek(file, 0L, SEEK_SET);
    char *image_buff = new char[file_size];

    fread(image_buff, 1, file_size, file);

    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "https://backend.facecloud.tevian.ru/api/v1/detect?fd_min_size=0&fd_max_size=0&fd_threshold=0.8&demographics=true&attributes=true&landmarks=false");

    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, image_buff);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE_LARGE, curl_off_t(file_size));
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);


    ret = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    curl = nullptr;
    curl_slist_free_all(headers);
    headers = nullptr;

    fclose(file);

    return std::string(response.ptr);
}

std::string CloudApi::
detectImage_ByImage(std::vector<char> imageBin)
{
    CURLcode ret;
    CURL *curl;
    struct curl_slist *headers;
    struct string response;
    init_string(&response);

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
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);


    ret = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    curl = nullptr;
    curl_slist_free_all(headers);
    headers = nullptr;

    return std::string(response.ptr);
}












