#pragma once

#include "../nal/TruthEvaluators.hpp"

#include <pybind11/pybind11.h>

namespace seqnars::nal
{
namespace py = pybind11;

inline auto pybind_decl__truth_evaluators(py::module_ &) -> void {}
inline auto pybind__truth_evaluators(py::module_ &) -> void {}

} // namespace seqnars::nal
