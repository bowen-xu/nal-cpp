#pragma once
#include <pybind11/pybind11.h>
#include "budget.hpp"

namespace NAL
{
namespace py = pybind11;

inline void pybind_decl__budget(py::module &m)
{
    // volatile auto pyBudget = py::class_<Budget, shared_ptr<Budget>, Parent_of_Budget>(m, "Budget");
    volatile auto pyBudget = py::class_<Budget>(m, "Budget");
}
void pybind__budget(py::module &m);

} // namespace NAL
