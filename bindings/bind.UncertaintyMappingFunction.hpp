#pragma once

#include "../nal/UncertaintyMappingFunction.hpp"

#include <pybind11/pybind11.h>

namespace seqnars::nal
{
namespace py = pybind11;

inline auto pybind_decl__uncertainty_mapping_function(py::module_ &) -> void {}
auto pybind__uncertainty_mapping_function(py::module_ &m) -> void;

} // namespace seqnars::nal
