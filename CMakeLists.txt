cmake_minimum_required(VERSION 3.20)

project(ext_py_with_c_c++)
include( CMakeParseArguments )

message(STATUS "C/CXX_FLAGS must set -O3 or will occur a segment fault")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3 -fPIC")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O3 -fPIC")

find_package(PythonLibs REQUIRED)

set(PYTHON_INCLUDE_DIR "/usr/include/python3.10")

macro(add_py_module target)
	set(multiValueArgs LINK_LIBS SOURCES)
	cmake_parse_arguments(add_py_module "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )
	add_library(${target} ${add_py_module_SOURCES})
	target_include_directories(${target} PRIVATE ${PYTHON_INCLUDE_DIR})
	target_link_libraries(${target} PRIVATE ${add_py_module_LINK_LIBS})
	set_target_properties(${target} PROPERTIES PREFIX "")
endmacro()

macro(add_py_embeding_bin target)
	set(multiValueArgs LINK_LIBS SOURCES)
	cmake_parse_arguments(add_py_embeding_bin "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )
	add_executable(${target} ${add_py_embeding_bin_SOURCES})
	target_include_directories(${target} PRIVATE ${PYTHON_INCLUDE_DIR})
	target_link_libraries(${target} PRIVATE ${add_py_embeding_bin_LINK_LIBS})
endmacro()

add_subdirectory(CPython)
add_subdirectory(boost_python)