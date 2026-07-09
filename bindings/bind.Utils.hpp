#pragma once

#include "../nal/Utils.hpp"

#include <pybind11/pybind11.h>

namespace seqnars::nal
{
namespace py = pybind11;

inline auto pybind_decl__utils(py::module_ &) -> void {}
inline auto pybind__utils(py::module_ &) -> void {}

} // namespace seqnars::nal
