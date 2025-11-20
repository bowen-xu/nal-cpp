#include "Truth.h"
#include "Budget.h"
#include <iostream>
using namespace NAL;

void NAL::foo() { std::cout << "foo" << std::endl; }

void NAL::pybind_truth(py::module &m)
{
#ifdef PYMODULE
    using classType = py::class_<NAL::Truth, NAL::pTruth>;
    const char *className = "Truth";
    PyObject *pyObj_;
    if (!py::hasattr(m, className))
        pyObj_ = classType(m, className).ptr();
    else
        pyObj_ = m.attr(className).ptr();
    auto pyClass_ = py::reinterpret_borrow<classType>(pyObj_);

    pyClass_.def(py::init([]() { return Truth::create(); }))
        .def(py::init([](double f, double c, double k) { return Truth::create(f, c, k); }), py::arg("f"), py::arg("c"),
             py::arg("k") = 1.0)
        .def(py::init([](double f, double c, bool is_temporal, int64_t ts_update, double k)
                      { return Truth::create(f, c, is_temporal, ts_update, k); }),
             py::arg("f"), py::arg("c"), py::arg("is_temporal"), py::arg("ts_update") = -1, py::arg("k") = 1.0)
        // .def(py::init([](double k)
        //               { return Truth::create(k); }),
        //  py::arg("k") = 1.0)
        .def_readwrite("f", &Truth::f)
        .def_readwrite("c", &Truth::c)
        .def_readwrite("k", &Truth::k)
        .def_readwrite("ts_update", &Truth::ts_update)
        .def_property_readonly("e", &Truth::e)
        .def("revise", py::overload_cast<const NAL::Truth &>(&Truth::revise), py::arg("truth"))
        .def("revise", py::overload_cast<double, double>(&Truth::revise_w), py::arg("w_p"), py::arg("w"))
        .def("revise", py::overload_cast<NAL::Truth &, int64_t, int64_t>(&Truth::revise), py::arg("truth"),
             py::arg("ts_now"), py::arg("duration") = 20)
        .def("revise", py::overload_cast<double, double, int64_t, int64_t>(&Truth::revise_w), py::arg("w_p"),
             py::arg("w"), py::arg("ts_now"), py::arg("duration") = 20)
        // .def("project", &Truth::project, py::arg("ts_now"), py::arg("duration") = 20, py::arg("forward_only") = true)
        .def("set_fc", py::overload_cast<double, double>(&Truth::set_fc), py::arg("f"), py::arg("c"))
        .def("set_fc", py::overload_cast<double, double, int64_t>(&Truth::set_fc), py::arg("f"), py::arg("c"),
             py::arg("ts_update"))
        .def("set_w", py::overload_cast<double, double>(&Truth::set_w), py::arg("w_p"), py::arg("w"))
        .def("set_w", py::overload_cast<double, double, int64_t>(&Truth::set_w), py::arg("w_p"), py::arg("w"),
             py::arg("ts_update"))
        .def_property_readonly("w", &Truth::w)
        .def_property_readonly("w_p", &Truth::w_p)
        .def_property_readonly("w_m", &Truth::w_m)
        .def_static("from_w", &Truth::from_w, py::arg("w_p"), py::arg("w"), py::arg("k") = 1.0)
        .def_static("calc_decay_factor", &Truth::calc_decay_factor)
        // .def("revise_w")
        .def("__repr__", &Truth::__repr__);

    // Define DesireValue as an alias for Truth
    m.attr("DesireValue") = m.attr("Truth");
#endif // PYMODULE
}
