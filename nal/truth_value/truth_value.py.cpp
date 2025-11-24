#include "truth_value.py.hpp"
#include <fmt/core.h>

namespace NAL
{

void pybind__truth_value(py::module &m)
{
    using classType = py::class_<TruthV>;
    const char *className = "TruthV";
    PyObject *pyObj_;
    if (!py::hasattr(m, className))
        pyObj_ = classType(m, className).ptr();
    else
        pyObj_ = m.attr(className).ptr();
    auto pyClass_ = py::reinterpret_borrow<classType>(pyObj_);

    pyClass_.def(py::init([]() { return TruthV(); }))
        .def(py::init([](double f, double c, double k) { return TruthV(f, c, k); }), py::arg("f"), py::arg("c"),
             py::arg("k") = 1.0)
        .def(py::init([](double f, double c, bool is_temporal, int64_t ts_update, double k)
                      { return TruthV(f, c, is_temporal, ts_update, k); }),
             py::arg("f"), py::arg("c"), py::arg("is_temporal"), py::arg("ts_update") = -1, py::arg("k") = 1.0)
        // .def(py::init([](double k)
        //               { return TruthV::create(k); }),
        //  py::arg("k") = 1.0)
        .def_readwrite("f", &TruthV::f)
        .def_readwrite("c", &TruthV::c)
        .def_readwrite("k", &TruthV::k)
        .def_readwrite("ts_update", &TruthV::ts_update)
        .def_property_readonly("e", &TruthV::e)
     //    .def("revise", py::overload_cast<const TruthV &>(&TruthV::revise), py::arg("truth"))
     //    .def("revise", py::overload_cast<double, double>(&TruthV::revise_w), py::arg("w_p"), py::arg("w"))
     //    .def("revise", py::overload_cast<TruthV &, int64_t, int64_t>(&TruthV::revise), py::arg("truth"),
     //         py::arg("ts_now"), py::arg("duration") = 20)
     //    .def("revise", py::overload_cast<double, double, int64_t, int64_t>(&TruthV::revise_w), py::arg("w_p"),
     //         py::arg("w"), py::arg("ts_now"), py::arg("duration") = 20)
     //    // .def("project", &TruthV::project, py::arg("ts_now"), py::arg("duration") = 20, py::arg("forward_only") =
     //    // true)
        .def("set_fc", py::overload_cast<double, double>(&TruthV::set_fc), py::arg("f"), py::arg("c"))
        .def("set_fc", py::overload_cast<double, double, int64_t>(&TruthV::set_fc), py::arg("f"), py::arg("c"),
             py::arg("ts_update"))
        .def("set_w", py::overload_cast<double, double>(&TruthV::set_w), py::arg("w_p"), py::arg("w"))
        .def("set_w", py::overload_cast<double, double, int64_t>(&TruthV::set_w), py::arg("w_p"), py::arg("w"),
             py::arg("ts_update"))
        .def_property_readonly("w", &TruthV::w)
        .def_property_readonly("w_p", &TruthV::w_p)
        .def_property_readonly("w_m", &TruthV::w_m)
        .def_static("from_w", &TruthV::from_w, py::arg("w_p"), py::arg("w"), py::arg("k") = 1.0)
        .def_static("calc_decay_factor", &TruthV::calc_decay_factor)
        // .def("revise_w")
        .def("__repr__", &TruthV::__repr__);

    // Define DesireValue as an alias for TruthV
    m.attr("DesireValue") = m.attr("TruthV");
}

} // namespace NAL
