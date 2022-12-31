cmake_minimum_required(VERSION 3.0)

project(tippy-platform-windows-runtime)

# GLFW3
add_library(glfw3 SHARED IMPORTED GLOBAL)
set_property(
        TARGET glfw3 PROPERTY IMPORTED_LOCATION
        ${CMAKE_CURRENT_SOURCE_DIR}/bin/x64/glfw3.dll
)
set_property(
        TARGET glfw3 PROPERTY IMPORTED_IMPLIB
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/x64/glfw3.lib
)
set_property(
        TARGET glfw3 PROPERTY INTERFACE_INCLUDE_DIRECTORIES
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
add_library(runtime::glfw3 ALIAS glfw3)

# ANGLE
add_library(angle SHARED IMPORTED GLOBAL)
set_property(
        TARGET angle PROPERTY IMPORTED_LOCATION
        ${CMAKE_CURRENT_SOURCE_DIR}/bin/x64/libGLESv2.dll
)
set_property(
        TARGET angle PROPERTY IMPORTED_IMPLIB
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/x64/libGLESv2.lib
)
set_property(
        TARGET angle PROPERTY INTERFACE_INCLUDE_DIRECTORIES
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
add_library(runtime::angle ALIAS angle)