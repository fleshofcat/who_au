cmake_minimum_required(VERSION 3.1)
project(who_au LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOMOC ON) // last
#set(CMAKE_AUTORCC ON)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(Qt5 COMPONENTS Core Quick REQUIRED)

#add_executable(${PROJECT_NAME} "main.cpp" "qml.qrc")
#target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
#target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Quick)

#target_link_libraries(${PROJECT_NAME} PRIVATE curlpp)

#target_include_directories(${PROJECT_NAME} PRIVATE "lib/curlpp/include")

add_subdirectory(lib/Catch2)
add_subdirectory(lib/curlpp)
add_subdirectory(lib/json)

add_subdirectory(cloud_api)
add_subdirectory(app)
#add_subdirectory(gui)
add_subdirectory(tests)


