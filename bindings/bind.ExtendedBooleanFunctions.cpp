#include "bind.ExtendedBooleanFunctions.hpp"

namespace seqnars::nal
{

auto pybind__extended_boolean_functions(py::module_ &m) -> void
{

    m.def("And", py::overload_cast<double, double>(&and_), "Definition:\n\tAnd(x1, x2) = x1 * x2");
    m.def("And", py::overload_cast<double, double, double>(&and_), "Definition:\n\tAnd(x1, x2, x3) = x1 * x2 * x3");
    m.def("And", py::overload_cast<double, double, double, double>(&and_),
          "Definition:\n\tAnd(x1, x2, x3, x4) = x1 * x2 * x3 * x4");
    m.def(
        "And",
        [](double x1, double x2, double x3, double x4, double x5, py::args xs)
        {
            auto values = std::vector<double>{x1, x2, x3, x4, x5};
            for (const auto &x : xs)
                values.push_back(x.cast<double>());
            return and_(values);
        },
        "Definition:\n\tAnd(x1, ..., xn) = x1 * ... * xn");

    m.def("Or", py::overload_cast<double, double>(&or_), "Definition:\n\tOr(x1, x2) = 1 - (1 - x1) * (1 - x2)");
    m.def("Or", py::overload_cast<double, double, double>(&or_),
          "Definition:\n\tOr(x1, x2, x3) = 1 - (1 - x1) * (1 - x2) * (1 - x3)");
    m.def("Or", py::overload_cast<double, double, double, double>(&or_),
          "Definition:\n\tOr(x1, x2, x3, x4) = 1 - (1 - x1) * (1 - x2) * (1 - x3) * (1 - x4)");
    m.def(
        "Or",
        [](double x1, double x2, double x3, double x4, double x5, py::args xs)
        {
            auto values = std::vector<double>{x1, x2, x3, x4, x5};
            for (const auto &x : xs)
                values.push_back(x.cast<double>());
            return or_(values);
        },
        "Definition:\n\tOr(x1, ..., xn) = 1 - (1 - x1) * ... * (1 - xn)");

    m.def("Not", &not_, "Definition:\n\tNot(x) = 1 - x");
}

} // namespace seqnars::nal
