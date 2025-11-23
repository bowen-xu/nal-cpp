#include <pybind11/pybind11.h>
#include "./nal.py.hpp"

using namespace NAL;
PYBIND11_MODULE(nal, m)
{
#ifdef PYMODULE
    m.doc() = R"pbdoc(
        Non-Axiomatic Logic module
    )pbdoc";
    pybind_decl__truth_value(m);
    pybind_decl__budget(m);

    pybind__truth_value(m);
    pybind__budget(m);
    pybind__uncertainty_mapping_function(m);
    pybind__truth_functions(m);
    pybind__truth_evaluators(m);
#endif // PYMODULE
}