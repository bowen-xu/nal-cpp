#pragma once
#include <pybind11/pybind11.h>
#include "truth_functions.hpp"

namespace NAL
{
namespace py = pybind11;

inline void pybind_decl__truth_functions(py::module &m) {}
void pybind__truth_functions(py::module &m);

} // namespace NAL
