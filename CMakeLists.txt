cmake_minimum_required(VERSION 3.20)
project(MyProject CXX)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

add_subdirectory(SDL3-3.4.16)

set(SOURCES 
main.cpp
Cpp/WU_Moduls.cpp
Cpp/wuSystem.cpp
Cpp/wuCicle.cpp
Cpp/wuObjects.cpp
Cpp/wuObjects_Buffer.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE Header)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)