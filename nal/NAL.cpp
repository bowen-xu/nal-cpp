#include "Truth.h"
#include "Budget.h"
#include "NAL.h"

using namespace NAL;

void NAL::pybind_functions(py::module &m)
{
#ifdef PYMODULE
    m.def("And", py::overload_cast<double, double>(&And), "Definition:\n\tAnd(x1, x2) = x1 * x2");
    m.def("And", py::overload_cast<double, double, double>(&And), "Definition:\n\tAnd(x1, x2, x3) = x1 * x2 * x3");
    m.def("And", py::overload_cast<double, double, double, double>(&And),
          "Definition:\n\tAnd(x1, x2, x3, x4) = x1 * x2 * x3 * x4");
    // m.def("And", py::overload_cast<initializer_list<double>>(&And), "Definition:\n\tAnd(x1, ..., xn) = x1 * ... *
    // xn");
    m.def(
        "And",
        [](double x1, double x2, double x3, double x4, double x5, py::args xs)
        {
            std::vector<double> values{x1, x2, x3, x4, x5};
            for (auto x : xs)
                values.push_back(x.cast<double>());
            return And(values);
        },
        "Definition:\n\tAnd(x1, ..., xn) = x1 * ... * xn");

    m.def("Or", py::overload_cast<double, double>(&Or), "Definition:\n\tOr(x1, x2) = 1 - (1 - x1) * (1 - x2)");
    m.def("Or", py::overload_cast<double, double, double>(&Or),
          "Definition:\n\tOr(x1, x2, x3) = 1 - (1 - x1) * (1 - x2) * (1 - x3)");
    m.def("Or", py::overload_cast<double, double, double, double>(&Or),
          "Definition:\n\tOr(x1, x2, x3, x4) = 1 - (1 - x1) * (1 - x2) * (1 - x3) * (1 - x4)");
    // m.def("Or", py::overload_cast<initializer_list<double>>(&Or), "Definition:\n\tOr(x1, ..., xn) = 1 - (1 - x1) *
    // ... * (1 - xn)");
    m.def(
        "Or",
        [](double x1, double x2, double x3, double x4, double x5, py::args xs)
        {
            std::vector<double> values{x1, x2, x3, x4, x5};
            for (auto x : xs)
                values.push_back(x.cast<double>());
            return Or(values);
        },
        "Definition:\n\tOr(x1, ..., xn) = 1 - (1 - x1) * ... * (1 - xn)");

    m.def("Not", &Not, "Definition:\n\tNot(x) = 1 - x");

    m.def("fc_to_w_plus", &fc_to_w_plus, "fc_to_w_plus function");
    m.def("fc_to_w", &fc_to_w, "fc_to_w function");
    m.def("fc_to_w_minus", &fc_to_w_minus, "fc_to_w_minus function");
    m.def("w_to_f", &w_to_f, "w_to_f function");
    m.def("w_to_c", &w_to_c, "w_to_c function");

    m.def("truth_from_w", &truth_from_w, "truth_from_w function");

    /* Truth-value functions */
    m.def("F_rev", py::overload_cast<const Truth &, const Truth &>(&F_rev), "Revision", py::arg("a"), py::arg("b"));
    m.def("F_rev", py::overload_cast<double, double, double, double>(&F_rev), "Revision", py::arg("f1"), py::arg("f2"),
          py::arg("c1"), py::arg("c2"));
    m.def("F_rev", py::overload_cast<const Truth &, const Truth &, Truth &>(&F_rev), "Revision", py::arg("a"),
          py::arg("b"), py::arg("out"));

    m.def("F_ded", py::overload_cast<const Truth &, const Truth &>(&F_ded), "Deduction", py::arg("a"), py::arg("b"));
    m.def("F_ded", py::overload_cast<double, double, double, double>(&F_ded), "Deduction", py::arg("f1"), py::arg("f2"),
          py::arg("c1"), py::arg("c2"));
    m.def("F_ded", py::overload_cast<const Truth &, const Truth &, Truth &>(&F_ded), "Deduction", py::arg("a"),
          py::arg("b"), py::arg("out"));

    m.def("F_ind", py::overload_cast<const Truth &, const Truth &>(&F_ind), "Induction", py::arg("a"), py::arg("b"));
    m.def("F_ind", py::overload_cast<double, double, double, double>(&F_ind), "Induction", py::arg("f1"), py::arg("f2"),
          py::arg("c1"), py::arg("c2"));
    m.def("F_ind", py::overload_cast<const Truth &, const Truth &, Truth &>(&F_ind), "Induction", py::arg("a"),
          py::arg("b"), py::arg("out"));

    m.def("F_abd", py::overload_cast<const Truth &, const Truth &>(&F_abd), "Abduction", py::arg("a"), py::arg("b"));
    m.def("F_abd", py::overload_cast<double, double, double, double>(&F_abd), "Abduction", py::arg("f1"), py::arg("f2"),
          py::arg("c1"), py::arg("c2"));
    m.def("F_abd", py::overload_cast<const Truth &, const Truth &, Truth &>(&F_abd), "Abduction", py::arg("a"),
          py::arg("b"), py::arg("out"));

    m.def("F_int", py::overload_cast<const Truth &, const Truth &>(&F_int), "Intersection", py::arg("a"), py::arg("b"));
    m.def("F_int", py::overload_cast<double, double, double, double>(&F_int), "Intersection", py::arg("f1"),
          py::arg("f2"), py::arg("c1"), py::arg("c2"));
    m.def("F_int", py::overload_cast<const Truth &, const Truth &, Truth &>(&F_int), "Intersection", py::arg("a"),
          py::arg("b"), py::arg("out"));

#endif // PYMODULE
}

PYBIND11_MODULE(nal, m)
{
#ifdef PYMODULE
    m.doc() = R"pbdoc(
        Non-Axiomatic Logic module
    )pbdoc";
    auto pyTruth = py::class_<NAL::Truth, NAL::pTruth>(m, "Truth");
    auto pyBudget = py::class_<NAL::Budget, NAL::pBudget>(m, "Budget");

    NAL::pybind_truth(m);
    NAL::pybind_budget(m);
    NAL::pybind_functions(m);
#endif // PYMODULE
}
