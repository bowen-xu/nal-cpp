#pragma once
#include <pybind11/pybind11.h>
#include "truth_value.hpp"


namespace NAL
{
namespace py = pybind11;

inline void pybind_decl__truth_value(py::module &m)
{
    // volatile auto pyTruthValue = py::class_<TruthValue, shared_ptr<TruthValue>, Parent_of_TruthValue>(m, "TruthValue");
    volatile auto pyTruthValue = py::class_<TruthV>(m, "TruthV");
}
void pybind__truth_value(py::module &m);

} // namespace NAL
