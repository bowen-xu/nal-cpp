#pragma once

#include "bind.ExtendedBooleanFunctions.hpp"
#include "bind.UncertaintyMappingFunction.hpp"
#include "bind.TruthValue.hpp"
#include "bind.TruthFunctions.hpp"
#include "bind.TruthEvaluators.hpp"
#include "bind.Budget.hpp"
#include "bind.Utils.hpp"

#include <pybind11/pybind11.h>

namespace seqnars::nal
{
namespace py = pybind11;

auto pybind_decl__nal(py::module_ &m) -> void;
auto pybind__nal(py::module_ &m) -> void;

} // namespace seqnars::nal
