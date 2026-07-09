#include "bind.TruthValue.hpp"

namespace seqnars::nal
{

auto pybind__truth_value(py::module_ &m) -> void
{
    using classType = py::class_<TruthValue>;
    const char *className = "TruthValue";
    PyObject *pyObj_;
    if (!py::hasattr(m, className))
        pyObj_ = classType(m, className).ptr();
    else
        pyObj_ = m.attr(className).ptr();
    auto pyClass_ = py::reinterpret_borrow<classType>(pyObj_);

    pyClass_.def(py::init([]() { return TruthValue(); }))
        .def(py::init([](double f, double c, double k) { return TruthValue(f, c, k); }), py::arg("f"), py::arg("c"),
             py::arg("k") = 1.0)
        .def(py::init([](double f, double c, bool is_temporal, int64_t ts_update, double k)
                      { return TruthValue(f, c, is_temporal, ts_update, k); }),
             py::arg("f"), py::arg("c"), py::arg("is_temporal"), py::arg("ts_update") = -1, py::arg("k") = 1.0)
        .def_readwrite("f", &TruthValue::f)
        .def_readwrite("c", &TruthValue::c)
        .def_readwrite("k", &TruthValue::k)
        .def_readwrite("ts_update", &TruthValue::ts_update)
        .def_property_readonly("e", &TruthValue::e)
        .def("set_fc", py::overload_cast<double, double>(&TruthValue::set_fc), py::arg("f"), py::arg("c"))
        .def("set_fc", py::overload_cast<double, double, int64_t>(&TruthValue::set_fc), py::arg("f"), py::arg("c"),
             py::arg("ts_update"))
        .def("set_w", py::overload_cast<double, double>(&TruthValue::set_w), py::arg("w_p"), py::arg("w"))
        .def("set_w", py::overload_cast<double, double, int64_t>(&TruthValue::set_w), py::arg("w_p"), py::arg("w"),
             py::arg("ts_update"))
        .def_property_readonly("w", &TruthValue::w)
        .def_property_readonly("w_p", &TruthValue::w_p)
        .def_property_readonly("w_m", &TruthValue::w_m)
        .def_static("from_w", &TruthValue::from_w, py::arg("w_p"), py::arg("w"), py::arg("k") = 1.0)
        .def_static("calc_decay_factor", &TruthValue::calc_decay_factor)
        .def("__repr__", &TruthValue::repr);

    // Python keeps the old short names as aliases for the canonical TruthValue type.
    m.attr("TruthV") = m.attr("TruthValue");
    m.attr("DesireValue") = m.attr("TruthValue");
    m.attr("DesireV") = m.attr("TruthValue");
}

} // namespace seqnars::nal
