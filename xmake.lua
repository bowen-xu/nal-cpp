add_rules("mode.debug", "mode.release", "mode.releasedbg")
set_languages("cxx23")

if is_mode("debug") then
    add_cxxflags("-Wall", "-Wextra", "-Wpedantic", {force = true})
end

add_requires("pybind11", {system = false})
add_requires("fmt")
add_requires("gtest")

local nal_srcs = os.files("nal/*.cpp")
local binding_srcs = os.files("bindings/*.cpp")

target("nal_cpp")
    set_kind("static")

    add_packages("pybind11", {public = true})
    add_packages("fmt", {public = true})

    add_includedirs(".", {public = true})
    add_files(nal_srcs)
    add_files(binding_srcs)

target("test_nal")
    set_kind("binary")

    add_packages("fmt")
    add_packages("gtest")
    add_includedirs(".")
    add_files(nal_srcs)
    add_files("tests/*.cpp")
