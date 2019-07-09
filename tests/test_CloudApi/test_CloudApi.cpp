#include <catch.hpp>

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <ios>

#include <CloudApi.h>

using namespace std;

TEST_CASE("Authentication test - for authentication(email, pass)", "[CloudApi]")
{
    // test manual auth
    CloudApi for_manual_auth;

    nlohmann::json response_json =
            nlohmann::json::parse(for_manual_auth.authentication
                                  ("who_au@mail.com", "pass"));

    REQUIRE(response_json["status_code"] == 200);
    REQUIRE(for_manual_auth.isLogged() == true);


    // test auth in construct

    CloudApi for_auto_auth("who_au@mail.com", "pass");
    REQUIRE(for_auto_auth.isLogged() == true);

    // test incorrect emale/pass

    CloudApi incorrect_login_cloud;

    nlohmann::json incorrect_login_json =
            nlohmann::json::parse(incorrect_login_cloud.authentication
                                  ("who_au@mail.com", "incorrect_pass"));

    REQUIRE(incorrect_login_json["status_code"] == 401);
    REQUIRE(incorrect_login_cloud.isLogged() == false);
}


TEST_CASE("Detect Image test - for detectImage(jpegBin)", "[CloudApi]")
{
    // common preparing // make jpegBin to work
    vector<char> jpegBin;

    ifstream file("../../who_au/tests/res/face.jpg");

    file.seekg (0, file.end);
    auto size = file.tellg();
    file.seekg (0, file.beg);

    jpegBin.resize((unsigned long)(size));

    file.read(jpegBin.data(), size);
    file.close();


    // test detectImage()

    CloudApi cloud("who_au@mail.com", "pass");

    string response = cloud.detectImage(jpegBin);

    nlohmann::json response_json = nlohmann::json::parse(response);

    REQUIRE(response_json["status_code"] == 200); // success


    // test usage detectImage() without a auth

    CloudApi unloggedCloud;

    nlohmann::json without_auth_json =
            nlohmann::json::parse(
                unloggedCloud.detectImage(jpegBin));

    REQUIRE(without_auth_json["message"] ==
            "authorization with token required");
}



