#include <pybind11/pybind11.h>
import non_axomatic_logic.py;
namespace py = pybind11;
using namespace NAL;
PYBIND11_MODULE(nal, m)
{
#ifdef PYMODULE
    m.doc() = R"pbdoc(
        Non-Axiomatic Logic module
    )pbdoc";
    auto pyTruth = py::class_<TruthV, pTruthV>(m, "TruthV");
    auto pyBudget = py::class_<Budget, pBudget>(m, "Budget");

    pybind_truth(m);
    pybind_budget(m);
    pybind_functions(m);
#endif // PYMODULE
}