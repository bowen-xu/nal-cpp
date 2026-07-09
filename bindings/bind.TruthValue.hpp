#pragma once

#include "../nal/TruthValue.hpp"

#include <pybind11/pybind11.h>

namespace seqnars::nal
{
namespace py = pybind11;

inline auto pybind_decl__truth_value(py::module_ &m) -> void
{
    volatile auto pyTruthValue = py::class_<TruthValue>(m, "TruthValue");
}
auto pybind__truth_value(py::module_ &m) -> void;

} // namespace seqnars::nal
