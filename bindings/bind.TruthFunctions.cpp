#include "bind.TruthFunctions.hpp"

namespace seqnars::nal
{

auto pybind__truth_functions(py::module_ &m) -> void
{
    /* TruthValue-value functions */
    m.def("F_rev", py::overload_cast<const TruthValue &, const TruthValue &>(&revision), "Revision", py::arg("a"),
          py::arg("b"));
    m.def("F_rev", py::overload_cast<double, double, double, double>(&revision), "Revision", py::arg("f1"),
          py::arg("f2"), py::arg("c1"), py::arg("c2"));
    m.def("F_rev", py::overload_cast<const TruthValue &, const TruthValue &, TruthValue &>(&revision), "Revision",
          py::arg("a"), py::arg("b"), py::arg("out"));

    m.def("F_ded", py::overload_cast<const TruthValue &, const TruthValue &>(&deduction), "Deduction", py::arg("a"),
          py::arg("b"));
    m.def("F_ded", py::overload_cast<double, double, double, double>(&deduction), "Deduction", py::arg("f1"),
          py::arg("f2"), py::arg("c1"), py::arg("c2"));
    m.def("F_ded", py::overload_cast<const TruthValue &, const TruthValue &, TruthValue &>(&deduction), "Deduction",
          py::arg("a"), py::arg("b"), py::arg("out"));

    m.def("F_ind", py::overload_cast<const TruthValue &, const TruthValue &>(&induction), "Induction", py::arg("a"),
          py::arg("b"));
    m.def("F_ind", py::overload_cast<double, double, double, double>(&induction), "Induction", py::arg("f1"),
          py::arg("f2"), py::arg("c1"), py::arg("c2"));
    m.def("F_ind", py::overload_cast<const TruthValue &, const TruthValue &, TruthValue &>(&induction), "Induction",
          py::arg("a"), py::arg("b"), py::arg("out"));

    m.def("F_abd", py::overload_cast<const TruthValue &, const TruthValue &>(&abduction), "Abduction", py::arg("a"),
          py::arg("b"));
    m.def("F_abd", py::overload_cast<double, double, double, double>(&abduction), "Abduction", py::arg("f1"),
          py::arg("f2"), py::arg("c1"), py::arg("c2"));
    m.def("F_abd", py::overload_cast<const TruthValue &, const TruthValue &, TruthValue &>(&abduction), "Abduction",
          py::arg("a"), py::arg("b"), py::arg("out"));

    m.def("F_int", py::overload_cast<const TruthValue &, const TruthValue &>(&intersection), "Intersection",
          py::arg("a"), py::arg("b"));
    m.def("F_int", py::overload_cast<double, double, double, double>(&intersection), "Intersection", py::arg("f1"),
          py::arg("f2"), py::arg("c1"), py::arg("c2"));
    m.def("F_int", py::overload_cast<const TruthValue &, const TruthValue &, TruthValue &>(&intersection),
          "Intersection", py::arg("a"), py::arg("b"), py::arg("out"));
}

} // namespace seqnars::nal
