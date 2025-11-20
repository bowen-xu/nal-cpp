#pragma once

#include <pybind11/pybind11.h>
#include "ExtendedBooleanFunctions.h"
#include "UncertaintyMappingFunctions.h"
#include "TruthFunctions.h"

namespace NAL
{
    namespace py = pybind11;

    void pybind_truth(py::module &m);
    void pybind_functions(py::module &m);
} // namespace NAL