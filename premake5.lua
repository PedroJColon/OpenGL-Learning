-- Premake5.lua

workspace "OpenGL-Learning"
    configurations { "Debug", "Release" }

project "OpenGL-Learning"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"

    links {"GL", "GLU", "glut"}

    files {"main.cpp", "src/header/*.h", "src/*.cpp"}

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"
