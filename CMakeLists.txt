cmake_minimum_required(VERSION 3.20)

project(ext_py_with_c_c++)


message(STATUS "C/CXX_FLAGS must set -O3 or will occur a segment fault")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3 -fPIC")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O3 -fPIC")

find_package(PythonLibs REQUIRED)

set(PYTHON_INCLUDE_DIR "/usr/include/python3.10")

macro(add_py_module target source link_libs)
	add_library(${target} ${source})
	target_include_directories(${target} PRIVATE ${PYTHON_INCLUDE_DIR})
	target_link_libraries(${target} PRIVATE ${link_libs})
	set_target_properties(${target} PROPERTIES PREFIX "")
endmacro()

add_subdirectory(CPython)
add_subdirectory(boost_python)