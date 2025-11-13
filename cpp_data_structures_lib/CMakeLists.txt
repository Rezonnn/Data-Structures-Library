cmake_minimum_required(VERSION 3.10)
project(CPPDataStructuresLib CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(data_structures_demo
    src/main.cpp
)

target_include_directories(data_structures_demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
