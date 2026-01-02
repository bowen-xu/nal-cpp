# nal-cpp

Core Non-Axiomatic Logic (NAL) numeric and logic components in C++23, focused on truth values, budgets, evaluators, and uncertainty mapping for reuse in C++ and Python projects.

To learn more of Non-Axiomatic Logic, please refer to [*Non-Axiomatic Logic A Model of Intelligent Reasoning (2nd Edition)*](https://www.worldscientific.com/worldscibooks/10.1142/14486?srsltid=AfmBOoo_cAQ0QsiivuIEeB2rI807_w7aTPzMnfRjorvdEtOgwDwZVmZM).

## Overview
- Truth value representation and revision: `TruthV`
- Budgeting and priority mechanism: `budget` module
- Truth functions and evaluators: `truth_functions`, `truth_evaluators`
- Extended boolean and uncertainty mapping: `extended_boolean_functions`, `uncertainty_mapping_function`
- Unified entry header: `nal/nal.hpp`

**Layout**
- `nal/`: core logic implementation
- `nal/**.py.cpp`: pybind11 bindings
- `nal/Config.h`: default parameters (`NAL::CONFIG`)
- `xmake.lua`: build configuration
- `refresh_compile_commands.sh`: compilation database helper

## Build
Uses `xmake` and pulls `fmt` and `pybind11` via package management.

```bash
xmake f -m release
xmake build
```

Target: `non-axiomatic-logic` (static library).

## C++ Example
```cpp
#include "nal/nal.hpp"

int main() {
    NAL::TruthV a(0.6, 0.9);
    NAL::TruthV b(0.4, 0.8);
    a.revise(b);
    return 0;
}
```

## Python Bindings
The repository includes pybind11 bindings in `nal/*.py.cpp` and `nal/*.py.hpp` (entry at `nal/nal.py.cpp`).
To build a Python module, switch the target to a shared library and define the `PYMODULE` macro in your build setup.

**Generate Python Module**

1. Clone the repo. Suppose the directory is `./nal-cpp`.
2. Copy the file `_generate_stub.py` (in `https://github.com/bowen-xu/python-cpp-example/blob/main/_generate_stub.py`) to the root
3. Create an xmake file for building the module. Example:
```lua
add_rules("mode.debug", "mode.release", "mode.releasedbg")
set_languages("cxx23")

add_requires("pybind11", {system = false})

includes("nal-cpp")

local project_root = path.join(os.scriptdir(), ".")
local py_root = project_root

target("nal")
    add_defines("PYMODULE")
    add_rules("python.module")
    add_packages("pybind11")
    add_packages("fmt")
    add_deps("non-axiomatic-logic")
    add_files(nal_pybind_srcs)


    local module_dir = path.join(py_root, "./")
    set_targetdir(module_dir)

    after_build(function (target)
        cprint("${blue}Generate stub for " .. target:name() .. "...")
        local py = os.getenv("CONDA_PREFIX") and (os.getenv("CONDA_PREFIX") .. "/bin/python") or "python"
        cprint("${yellow}Using python: " .. py)
        os.exec(py .. " --version")
        os.exec(py .. " " .. project_root .. "/_generate_stub.py " .. " --root " .. module_dir .. " -p " .. target:name() .. " --single True")
    end)
```
4. Compile by running `xmake build`.