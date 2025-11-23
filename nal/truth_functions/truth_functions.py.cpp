#include "truth_functions.py.hpp"
#include <fmt/core.h>

namespace NAL
{

void pybind__truth_functions(py::module &m)
{
    /* TruthV-value functions */
    m.def("F_rev", py::overload_cast<const TruthV &, const TruthV &>(&F_rev), "Revision", py::arg("a"), py::arg("b"));
    m.def("F_rev", py::overload_cast<double, double, double, double>(&F_rev), "Revision", py::arg("f1"), py::arg("f2"),
          py::arg("c1"), py::arg("c2"));
    m.def("F_rev", py::overload_cast<const TruthV &, const TruthV &, TruthV &>(&F_rev), "Revision", py::arg("a"),
          py::arg("b"), py::arg("out"));

    m.def("F_ded", py::overload_cast<const TruthV &, const TruthV &>(&F_ded), "Deduction", py::arg("a"), py::arg("b"));
    m.def("F_ded", py::overload_cast<double, double, double, double>(&F_ded), "Deduction", py::arg("f1"), py::arg("f2"),
          py::arg("c1"), py::arg("c2"));
    m.def("F_ded", py::overload_cast<const TruthV &, const TruthV &, TruthV &>(&F_ded), "Deduction", py::arg("a"),
          py::arg("b"), py::arg("out"));

    m.def("F_ind", py::overload_cast<const TruthV &, const TruthV &>(&F_ind), "Induction", py::arg("a"), py::arg("b"));
    m.def("F_ind", py::overload_cast<double, double, double, double>(&F_ind), "Induction", py::arg("f1"), py::arg("f2"),
          py::arg("c1"), py::arg("c2"));
    m.def("F_ind", py::overload_cast<const TruthV &, const TruthV &, TruthV &>(&F_ind), "Induction", py::arg("a"),
          py::arg("b"), py::arg("out"));

    m.def("F_abd", py::overload_cast<const TruthV &, const TruthV &>(&F_abd), "Abduction", py::arg("a"), py::arg("b"));
    m.def("F_abd", py::overload_cast<double, double, double, double>(&F_abd), "Abduction", py::arg("f1"), py::arg("f2"),
          py::arg("c1"), py::arg("c2"));
    m.def("F_abd", py::overload_cast<const TruthV &, const TruthV &, TruthV &>(&F_abd), "Abduction", py::arg("a"),
          py::arg("b"), py::arg("out"));

    m.def("F_int", py::overload_cast<const TruthV &, const TruthV &>(&F_int), "Intersection", py::arg("a"),
          py::arg("b"));
    m.def("F_int", py::overload_cast<double, double, double, double>(&F_int), "Intersection", py::arg("f1"),
          py::arg("f2"), py::arg("c1"), py::arg("c2"));
    m.def("F_int", py::overload_cast<const TruthV &, const TruthV &, TruthV &>(&F_int), "Intersection", py::arg("a"),
          py::arg("b"), py::arg("out"));
}

} // namespace NAL
