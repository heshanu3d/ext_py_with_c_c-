#include<string>
#include<boost/python.hpp>
 
using namespace std;
using namespace boost::python;
class World {
public:
    void set(string msg) { this->msg = msg; }
    string greet(string str) { return str; }
	string showmsg() { return msg; }
    string msg;
};
BOOST_PYTHON_MODULE(hello) //导出的module 名字
{
	class_<World>("World")
			.def("greet", &World::greet)
			.def("set", &World::set)
			.def("showmsg", &World::showmsg);
}