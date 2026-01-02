# nal-cpp

Core Non-Axiomatic Logic (NAL) numeric and logic components in C++23, focused on truth values, budgets, evaluators, and uncertainty mapping for reuse in C++ projects.

**Overview**
- Truth value representation and revision: `TruthV` (frequency/confidence/weight)
- Budgeting and priority mechanism: `budget` module
- Truth functions and evaluators: `truth_functions`, `truth_evaluators`
- Extended boolean and uncertainty mapping: `extended_boolean_functions`, `uncertainty_mapping_function`
- Unified entry header: `nal/nal.hpp`

**Build**
Uses `xmake` and pulls `fmt` and `pybind11` via package management.

```bash
xmake f -m release
xmake build
```

Target: `non-axiomatic-logic` (static library).

**C++ Example**
```cpp
#include "nal/nal.hpp"

int main() {
    NAL::TruthV a(0.6, 0.9);
    NAL::TruthV b(0.4, 0.8);
    a.revise(b);
    return 0;
}
```

**Python Bindings**
The repository includes pybind11 bindings in `nal/*.py.cpp` and `nal/*.py.hpp` (entry at `nal/nal.py.cpp`).
To build a Python module, switch the target to a shared library and define the `PYMODULE` macro in your build setup.

**Layout**
- `nal/`: core logic implementation
- `nal/**.py.cpp`: pybind11 bindings
- `nal/Config.h`: default parameters (`NAL::CONFIG`)
- `xmake.lua`: build configuration
- `refresh_compile_commands.sh`: compilation database helper
