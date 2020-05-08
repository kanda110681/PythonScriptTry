//#include "pch.h"
#include <pybind11/pybind11.h>
#include <string>

#include "MyMath.h"
#include "GlobalFuncs.h"
//#include "GlobalFuncs.cpp"

namespace py = pybind11;

PYBIND11_MODULE(igold, m)
{
	m.attr("__version__") = "1.0";

	m.def("mul", &mul, R"pbdoc(multiplication of two ints.)pbdoc");
	m.def("div", &division, R"pbdoc(division of two ints.)pbdoc");

	py::class_<MyMath>(m, "igtMath")
		.def(py::init<>())
		.def(py::init<int, int>())
		.def("add", py::overload_cast<>(&MyMath::add), R"pbdoc(addition based on initial values)pbdoc")
		.def("add", py::overload_cast<int, int>(&MyMath::add), R"pbdoc(addition of two ints.)pbdoc")
		.def("details", py::overload_cast<>(&MyMath::details), R"pbdoc(display class name.)pbdoc");
		

}