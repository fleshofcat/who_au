project(app LANGUAGES CXX)

add_library(${PROJECT_NAME} "who_au.cpp" "who_au.h" "i_user_interface.h")
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/cloud_api)

target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} PRIVATE cloud_api)



