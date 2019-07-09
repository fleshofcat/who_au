cmake_minimum_required(VERSION 3.1)
project(who_au LANGUAGES CXX)

find_package(CURL REQUIRED)

add_subdirectory(lib/Catch2)
#add_subdirectory(lib/curlpp)
add_subdirectory(lib/json)

add_subdirectory(cloud_api)
add_subdirectory(app)
#add_subdirectory(gui)
add_subdirectory(tests)


