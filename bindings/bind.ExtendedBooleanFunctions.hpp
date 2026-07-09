#pragma once

#include "../nal/ExtendedBooleanFunctions.hpp"

#include <pybind11/pybind11.h>

namespace seqnars::nal
{
namespace py = pybind11;

inline auto pybind_decl__extended_boolean_functions(py::module_ &) -> void {}
auto pybind__extended_boolean_functions(py::module_ &m) -> void;

} // namespace seqnars::nal
