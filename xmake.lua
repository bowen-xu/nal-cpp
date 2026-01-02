add_rules("mode.debug", "mode.release", "mode.releasedbg")
set_languages("cxx23")

add_requires("pybind11")
add_requires("fmt")

nal_pybind_srcs = "deps/nal-cpp/nal/nal.py.cpp"

local srcs = os.files("nal/**.py.cpp")
nal_pybind_srcs = {}
for _, v in ipairs(srcs) do
    table.insert(nal_pybind_srcs, path.join(os.scriptdir(), v))
end


target("non-axiomatic-logic")
    set_kind("static")
    add_packages("pybind11")
    add_packages("fmt")

    add_includedirs(".", {public = true})
    add_files(srcs)
