project(cloud_api)

add_library(${PROJECT_NAME} "CloudApi.cpp" "CloudApi.h")

target_link_libraries(${PROJECT_NAME} PRIVATE curl)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread") #TODO
