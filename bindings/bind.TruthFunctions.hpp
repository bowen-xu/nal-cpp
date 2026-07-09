#pragma once

#include "../nal/TruthFunctions.hpp"

#include <pybind11/pybind11.h>

namespace seqnars::nal
{
namespace py = pybind11;

inline auto pybind_decl__truth_functions(py::module_ &) -> void {}
auto pybind__truth_functions(py::module_ &m) -> void;

} // namespace seqnars::nal
