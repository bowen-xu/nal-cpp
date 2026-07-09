#include "bind.Budget.hpp"
#include <fmt/core.h>

namespace seqnars::nal
{

auto pybind__budget(py::module_ &m) -> void
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
        .def(py::init<double, double, double>(), py::arg("p") = Budget::PRIORITY_DEFAULT,
             py::arg("d") = Budget::DURABILITY_DEFAULT, py::arg("q") = Budget::QUALITY_DEFAULT)
        .def_readwrite("p", &Budget::priority)
        .def_readwrite("d", &Budget::durability)
        .def_readwrite("q", &Budget::quality)
        .def_readwrite("ts_update", &Budget::ts_update)
        .def("decay", &Budget::decay, py::arg("ts_now"))
        .def("excite_p", &Budget::excite_p, py::arg("a"), py::arg("stubbornness") = 0.1)
        .def("inhibit_p", &Budget::inhibit_p, py::arg("a"), py::arg("stubbornness") = 0.1)
        .def_static("calc_durability", &Budget::calc_durability, py::arg("half_life_period"))
        .def("__repr__", [](const Budget &self)
             { return fmt::format("<Budget: ${:.2f};{:.2f};{:.2f}$>", self.priority, self.durability, self.quality); });
}

} // namespace seqnars::nal
