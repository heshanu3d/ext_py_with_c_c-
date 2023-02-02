set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR})

add_py_module(test
	SOURCES test.cpp 
	LINK_LIBS -lboost_python310)
add_py_module(hello
	SOURCES hello.cpp 
	LINK_LIBS -lboost_python310)

set(libs -lboost_python310 ${PYTHON_LIBRARIES})

add_py_embeding_bin(boost_python_main 
	SOURCES main.cpp
	LINK_LIBS ${libs})
