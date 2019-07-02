project(app LANGUAGES CXX)

add_library(${PROJECT_NAME} "rename.cpp" "rename.h")

target_include_directories(${PROJECT_NAME} PUBLIC ../lib/curlpp/include)

target_link_libraries(${PROJECT_NAME} PRIVATE curlpp)

#target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)





#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
