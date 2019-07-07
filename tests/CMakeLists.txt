project(tests)

add_executable(${PROJECT_NAME} "main.cpp" "test_CloudApi/test_CloudApi.cpp")

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/app)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/lib/Catch2/include)

target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} PRIVATE app)

set(JSON_BuildTests OFF CACHE INTERNAL "")



