#include<string>
#include<boost/python.hpp>
 
using namespace std;
using namespace boost::python;
class World {
public:
	World() = default;
	World(string s) : _msg(s) {}
    void set(string msg) { this->_msg = msg; }
    string greet(string str) { return str; }
	string showmsg() { return _msg; }
    string msg;
	string _msg;
};
struct Var {
   	Var(std::string name) : name(name), value() {}
    std::string const name;
    float value;
};
// struct Num {
// 	Num();
//     float get() const;
//     void set(float value);
// };
class Base {
public:
	virtual ~Base() {};
	virtual int f() { return 0; };
	virtual float g() = 0;
};

class BaseWrap : public Base, public wrapper<Base> {
public:
	float g() {
		return get_override("g")();
	}
	int f() {
		
		if (override f = get_override("f"))
			return f();
		return Base::f();
	}
	int default_f() {return Base::f();}
};

class Derived : public Base {
public:
	int f() override { return 123; }
	float g() override { return 0.9; }
};

Base* factory() {
	return new Derived();
}

BOOST_PYTHON_MODULE(hello) //导出的module 名字
{
	class_<World>("World", init<string>())
		.def(init<>())
		.def("greet", &World::greet)
		.def("set", &World::set)
		.def("showmsg", &World::showmsg)
		.def_readwrite("msg", &World::msg)
		.def_readonly("_msg", &World::_msg);
	class_<Var>("Var", init<std::string>())
		.def_readonly("name", &Var::name)
		.def_readwrite("value", &Var::value);
	// class_<Num>("Num")
	// 	.add_property("value", &Num::get, &Num::set)
	// 	.add_property("rovalue", &Num::get);
	class_<Derived>("Derived")
		.def("f", &Derived::f)
		.def("g", &Derived::g);
	// def("b", b);
	// def("d", d);
	def("factory", factory, return_value_policy<manage_new_object>());
	class_<BaseWrap, boost::noncopyable>("Base")
		.def("g", pure_virtual(&Base::g))
		.def("f", &Base::f, &BaseWrap::default_f);
}