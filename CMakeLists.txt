cmake_minimum_required(VERSION 3.5)

project(StudentDBApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(StudentDBApp main.cpp)

target_link_libraries(StudentDBApp Qt5::Widgets)
