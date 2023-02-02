#include <iostream>
#include <boost/python.hpp>
using namespace std;
using namespace boost::python;

string python_code = 
"if __name__ == '__main__':\n"
"    with open('main.cpp', 'r') as f:\n"
"        for line in f.readlines():\n"
"            print(line, end='')\n";

int main() {
    Py_Initialize();
    object main_module = import("__main__");
    object main_namespace = main_module.attr("__dict__");
    object read_main_from_string = exec(python_code.c_str(), main_namespace);
    object read_main_from_file = exec_file("python_code.txt", main_namespace);

    return 0;
}
