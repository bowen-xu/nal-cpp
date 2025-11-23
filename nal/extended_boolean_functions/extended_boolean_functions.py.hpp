#pragma once
#include <pybind11/pybind11.h>
#include "extended_boolean_functions.hpp"

namespace NAL
{
namespace py = pybind11;

inline void pybind_decl__extended_boolean_functions(py::module &m) {}
void pybind__extended_boolean_functions(py::module &m);

} // namespace NAL
