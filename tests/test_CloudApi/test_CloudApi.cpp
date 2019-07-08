#include <catch.hpp>
#include <nlohmann/json.hpp>
#include <CloudApi.h>
#include <fstream>
#include <iostream>
#include <ios>

using namespace std;

TEST_CASE("Detect Face by image path", "[CloudApi]")
{
    std::string response = CloudApi::detectImage_hard("../../who_au/tests/res/people.jpg");

    nlohmann::json response_json = nlohmann::json::parse(response);
    auto q = response_json["status_code"];

//    std::cout << response << std::endl;

    REQUIRE(response_json["status_code"] == 200);
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

    string response = CloudApi::detectImage_ByImage(binImage);

    nlohmann::json response_json = nlohmann::json::parse(response);
    auto q = response_json["status_code"];

//    std::cout << response << std::endl;

    REQUIRE(response_json["status_code"] == 200);
}





