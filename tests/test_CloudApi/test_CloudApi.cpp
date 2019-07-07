#include <catch.hpp>
#include <nlohmann/json.hpp>
//#include <json/json.h>
#include <CloudApi.h>


TEST_CASE("Face detection test", "[CloudApi]")
{
    std::string response = CloudApi::detectImage_hard();


    nlohmann::json response_json = nlohmann::json::parse(response);
    auto q = response_json["status_code"];


    REQUIRE(response_json["status_code"] == 200);





//    Json::Value response_json(response);
//    Json::Reader reader;
//    reader.parse(response, response_json);
//    std::cout << response_json["status_code"].asString() << std::endl;
//    REQUIRE(response_json["status_code"].asString() == "200");
}





