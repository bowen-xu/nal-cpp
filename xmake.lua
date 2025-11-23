add_rules("mode.debug", "mode.release", "mode.releasedbg")
set_languages("cxx23")

-- -- local project_root = path.join(os.scriptdir(), "../../..")
-- local module_dir = path.join(project_root, "mind")
-- local py_root = project_root
-- nal_libs = path.join(module_dir, "libs/nal")


add_requires("pybind11")
add_requires("fmt")

-- local srcs = os.files("./*.cpp")
-- nal_includes = {
--     path.join(os.scriptdir(), ".")
-- }
-- local nal_srcs = {}
-- for _, v in ipairs(srcs) do
--     table.insert(nal_srcs, path.join(os.scriptdir(), v))
-- end


-- target("nal")
--     add_defines("PYMODULE")
--     add_rules("python.library", {soabi = true})
--     add_packages("pybind11")
--     add_packages("fmt")

--     add_files(srcs)
--     add_includedirs(nal_includes)

--     set_targetdir(module_dir)

--     after_build(function (target)
--         cprint("${blue}Generate stub for " .. target:name() .. "...")
--         local py = os.getenv("CONDA_PREFIX") and (os.getenv("CONDA_PREFIX") .. "/bin/python") or "python"
--         cprint("${yellow}Using python: " .. py)
--         os.exec(py .. " --version")
--         os.exec(py .. " " .. py_root .. "/_generate_stub.py " .. " --root " .. module_dir .. " -p " .. target:name() .. " --single True")
--     end)

nal_pybind_srcs = "deps/nal-cpp/nal/nal.py.cpp"

-- nal_pybind_srcs = os.files("nal/*.py.cxx", {rootdir = os.scriptdir()})


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
