add_py_module(spam spammodule.c ${PYTHON_LIBRARIES})

add_executable(main main.c)
target_include_directories(main PRIVATE ${PYTHON_INCLUDE_DIR})
target_link_libraries(main PRIVATE ${PYTHON_LIBRARIES} spam)