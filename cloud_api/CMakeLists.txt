project(cloud_api)

add_library(${PROJECT_NAME} "CloudApi.cpp" "CloudApi.h")

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/lib/curlpp/include) #TODO maby made private
target_link_libraries(${PROJECT_NAME} PUBLIC curlpp)
add_dependencies(${PROJECT_NAME} curlpp)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread") #TODO
