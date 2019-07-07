project(app LANGUAGES CXX)

#SET(PLATFORM_SPECIFIC_LIBS "-lpthread")

#add_library(${PROJECT_NAME} "testFaceApi.cpp" "testFaceApi.h")
add_library(${PROJECT_NAME} "CloudApi.cpp" "CloudApi.h")

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/lib/curlpp/include) #TODO mabe made private

target_link_libraries(${PROJECT_NAME} PUBLIC curlpp)
add_dependencies(${PROJECT_NAME} curlpp)

#add_executable(api_test "api_test.h" "api_test.cpp")
#target_link_libraries(api_test ${PROJECT_NAME})
#add_dependencies(api_test ${PROJECT_NAME})


SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

#target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)



#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
