cmake_minimum_required(VERSION 3.22)

project(MIPSSimulator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file (GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(MIPSSimulator ${SRC_FILES})
target_include_directories(MIPSSimulator PRIVATE ${CMAKE_SOURCE_DIR}/include)