#pragma once
#include <pybind11/pybind11.h>
#include "uncertainty_mapping_function.hpp"

namespace NAL
{
namespace py = pybind11;

inline void pybind_decl__uncertainty_mapping_function(py::module &m) {}
void pybind__uncertainty_mapping_function(py::module &m);

} // namespace NAL
