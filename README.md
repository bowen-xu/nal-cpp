# nal-cpp

Core Non-Axiomatic Logic (NAL) numeric and logic components in C++23, focused on truth values, budgets, evaluators, and uncertainty mapping for reuse in C++ and Python projects.

To learn more of Non-Axiomatic Logic, please refer to [*Non-Axiomatic Logic A Model of Intelligent Reasoning (2nd Edition)*](https://www.worldscientific.com/worldscibooks/10.1142/14486?srsltid=AfmBOoo_cAQ0QsiivuIEeB2rI807_w7aTPzMnfRjorvdEtOgwDwZVmZM).

## Overview
- Truth value representation and revision: `TruthValue`
- Budgeting and priority mechanism: `Budget`
- Truth functions and evaluators: `TruthFunctions`, `TruthEvaluators`
- Extended boolean and uncertainty mapping: `ExtendedBooleanFunctions`, `UncertaintyMappingFunction`
- Unified entry header: `nal/Nal.hpp`

**Layout**
- `nal/`: core logic implementation
- `bindings/`: pybind11 binding registration functions (`bind.*`)
- `nal/Config.hpp`: default parameters (`seqnars::nal::config`)
- `xmake.lua`: build configuration
- `refresh_compile_commands.sh`: compilation database helper

## Build
Uses `xmake` and pulls `fmt` and `pybind11` via package management.

```bash
xmake config -m release
xmake build
```

Target: `nal_cpp` (static library).

## C++ Example
```cpp
#include "nal/Nal.hpp"

auto main() -> int
{
    seqnars::nal::TruthValue a(0.6, 0.9);
    seqnars::nal::TruthValue b(0.4, 0.8);
    a.revise(b);
    return 0;
}
```

## Python Bindings
The repository includes pybind11 binding registration functions in `bindings/bind.*.cpp` and `bindings/bind.*.hpp`.

`nal-cpp` is not intended to build a standalone `nal` Python extension module in the parent SeqNARS project. Instead, it exposes callable binding functions that the parent `mind` extension module can call while registering `mind.nal`.

Entry points:

```cpp
seqnars::nal::pybind_decl__nal(py::module_ &m);
seqnars::nal::pybind__nal(py::module_ &m);
```

Expected parent-module pattern:

```cpp
PYBIND11_MODULE(mind, m)
{
    auto nal = m.def_submodule("nal");

    seqnars::nal::pybind_decl__nal(nal);
    seqnars::nal::pybind__nal(nal);
}
```
