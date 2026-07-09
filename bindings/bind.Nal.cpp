#include "bind.Nal.hpp"

namespace seqnars::nal
{

auto pybind_decl__nal(py::module_ &m) -> void
{
    m.doc() = R"pbdoc(
        Non-Axiomatic Logic module
    )pbdoc";

    pybind_decl__truth_value(m);
    pybind_decl__budget(m);
    pybind_decl__uncertainty_mapping_function(m);
    pybind_decl__truth_functions(m);
    pybind_decl__truth_evaluators(m);
    pybind_decl__extended_boolean_functions(m);
    pybind_decl__utils(m);
}

auto pybind__nal(py::module_ &m) -> void
{
    pybind__truth_value(m);
    pybind__budget(m);
    pybind__uncertainty_mapping_function(m);
    pybind__truth_functions(m);
    pybind__truth_evaluators(m);
    pybind__extended_boolean_functions(m);
    pybind__utils(m);
}

} // namespace seqnars::nal
