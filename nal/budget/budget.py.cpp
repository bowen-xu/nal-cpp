#include "budget.py.hpp"
#include <fmt/core.h>

namespace NAL
{

void pybind__budget(py::module &m)
{
    using classType = py::class_<Budget>;
    const char *className = "Budget";
    PyObject *pyObj_;
    if (!py::hasattr(m, className))
        pyObj_ = classType(m, className).ptr();
    else
        pyObj_ = m.attr(className).ptr();
    auto pyClass_ = py::reinterpret_borrow<classType>(pyObj_);

    pyClass_
        .def(py::init<float, float, float>(), py::arg("p") = Budget::_priority_default,
             py::arg("d") = Budget::_durability_default, py::arg("q") = Budget::_quality_default)
        .def_readwrite("p", &Budget::priority)
        .def_readwrite("d", &Budget::durability)
        .def_readwrite("q", &Budget::quality)
        .def_readwrite("ts_update", &Budget::ts_update)
        .def("decay", &Budget::decay, py::arg("ts_now"))
        .def("excite_p", &Budget::excite_p, py::arg("a"), py::arg("stubbornness") = 0.1)
        .def("inhibit_p", &Budget::inhibit_p, py::arg("a"), py::arg("stubbornness") = 0.1)
        .def_static("calc_durability", &Budget::calc_durability, py::arg("half_life_period"))
        .def("__repr__", [](Budget &self)
             { return fmt::format("<Budget: ${:.2f};{:.2f};{:.2f}$>", self.priority, self.durability, self.quality); });
}

} // namespace NAL
