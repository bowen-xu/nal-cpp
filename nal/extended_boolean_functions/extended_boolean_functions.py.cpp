#include "extended_boolean_functions.py.hpp"
#include <fmt/core.h>

namespace NAL
{

void pybind__extended_boolean_functions(py::module &m)
{

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
    // m.def("Or", py::overload_cast<initializer_list<double>>(&Or), "Definition:\n\tOr(x1, ..., xn) = 1 - (1 - x1)
    // *
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
}

} // namespace NAL
