cmake_minimum_required(VERSION 3.20)

project(ext_py_with_c_c++)


message(STATUS "C/CXX_FLAGS must set -O3 or will occur a segment fault")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3 -fPIC")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O3 -fPIC")

find_package(PythonLibs REQUIRED)

add_subdirectory(CPython)
