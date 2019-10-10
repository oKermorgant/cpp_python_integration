#include <pybind11/pybind11.h>

#include "robot.h"

namespace py = pybind11;

PYBIND11_MODULE(robot_libpb, m) {
    py::class_<Robot>(m, "Robot")
        .def(py::init<>())
        .def(py::init<double>())
        .def(py::init<double,double>())
        .def(py::init<double,double,double>())
        .def(py::init<double, double, double, std::string>())
        .def("printPosition", &Robot::printPosition)
        .def("bigComputation", &Robot::bigComputation);
#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
