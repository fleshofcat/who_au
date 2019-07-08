#include <catch.hpp>
#include <nlohmann/json.hpp>
#include <CloudApi.h>
#include <fstream>
#include <iostream>
#include <ios>

using namespace std;

TEST_CASE("Attempt to create exists user again", "[CloudApi]")
{
    std::string response = CloudApi::createDemoAccount(
                "myakotakota@mail.ru",
                "password");

    nlohmann::json response_json = nlohmann::json::parse(response);

    REQUIRE(response_json["error"]["email"][0]
            == "user with given email already exists");
}


TEST_CASE("Detect face by bin image", "[CloudApi]")
{
    vector<char> binImage;

    ifstream file("../../who_au/tests/res/face.jpg");

    file.seekg (0, file.end);
    auto size = file.tellg();
    file.seekg (0, file.beg);

    binImage.resize((unsigned long)(size));

    file.read(binImage.data(), size);
    file.close();

    string response = CloudApi::detectImage(binImage);

    nlohmann::json response_json = nlohmann::json::parse(response);

    REQUIRE(response_json["status_code"] == 200);
}





