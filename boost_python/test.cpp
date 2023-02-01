#include <string>
#include <boost/python.hpp>

char const* greet()
{
   return "hello, world";
}

int System(const char *cmd)
{
	return system(cmd);
}

BOOST_PYTHON_MODULE(test)
{
    using namespace boost::python;
    def("greet", greet);
	def("system", System);
}
