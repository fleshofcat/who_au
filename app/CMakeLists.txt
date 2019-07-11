project(app LANGUAGES CXX)

add_library(${PROJECT_NAME} "who_au.cpp" "who_au.h" "i_user_interface.h")
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/cloud_api) #TODO maby made private

target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} PRIVATE cloud_api)

#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")


