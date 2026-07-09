#pragma once

#include "../nal/Budget.hpp"

#include <pybind11/pybind11.h>

namespace seqnars::nal
{
namespace py = pybind11;

inline auto pybind_decl__budget(py::module_ &m) -> void { volatile auto pyBudget = py::class_<Budget>(m, "Budget"); }
auto pybind__budget(py::module_ &m) -> void;

} // namespace seqnars::nal
