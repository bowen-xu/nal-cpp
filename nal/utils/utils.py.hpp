#pragma once
#include <pybind11/pybind11.h>
#include "utils.hpp"


namespace NAL
{
namespace py = pybind11;

inline void pybind_decl__utils(py::module &m)
{
    // volatile auto pyUtils = py::class_<Utils, shared_ptr<Utils>, Parent_of_Utils>(m, "Utils");
    // volatile auto pyUtils = py::class_<Utils>(m, "Utils");
}
void pybind__utils(py::module &m);

} // namespace NAL
