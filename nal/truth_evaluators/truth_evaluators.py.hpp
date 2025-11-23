#pragma once
#include <pybind11/pybind11.h>
#include "truth_evaluators.hpp"

namespace NAL
{
namespace py = pybind11;

inline void pybind_decl__truth_evaluators(py::module &m) {}
void pybind__truth_evaluators(py::module &m);

} // namespace NAL
