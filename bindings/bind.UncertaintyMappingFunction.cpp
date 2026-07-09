#include "bind.UncertaintyMappingFunction.hpp"

namespace seqnars::nal
{

auto pybind__uncertainty_mapping_function(py::module_ &m) -> void
{
    m.def("fc_to_w_plus", &fc_to_w_plus, "fc_to_w_plus function");
    m.def("fc_to_w", &fc_to_w, "fc_to_w function");
    m.def("fc_to_w_minus", &fc_to_w_minus, "fc_to_w_minus function");
    m.def("w_to_f", &w_to_f, "w_to_f function");
    m.def("w_to_c", &w_to_c, "w_to_c function");

    m.def("truth_from_w", &truth_from_w, "truth_from_w function");
}

} // namespace seqnars::nal
