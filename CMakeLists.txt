cmake_minimum_required(VERSION 3.14)

project(ZeroJS
    VERSION 1.0.0
    DESCRIPTION "Header-only C++ library for generating static websites with HTMX"
    HOMEPAGE_URL "https://github.com/example/zero-js"
    LANGUAGES CXX
)

# Options
option(ZEROJS_BUILD_EXAMPLES "Build example applications" ON)

# Create header-only interface library
add_library(ZeroJS INTERFACE)
add_library(ZeroJS::ZeroJS ALIAS ZeroJS)

# Specify include directories
target_include_directories(ZeroJS INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

# Require C++17
target_compile_features(ZeroJS INTERFACE cxx_std_17)

# Build examples if requested
if(ZEROJS_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# Installation
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Install headers
install(FILES zero_js.hpp
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY src/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/src
    FILES_MATCHING PATTERN "*.hpp"
)

# Install the target
install(TARGETS ZeroJS
    EXPORT ZeroJSTargets
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Generate and install export file
install(EXPORT ZeroJSTargets
    FILE ZeroJSTargets.cmake
    NAMESPACE ZeroJS::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ZeroJS
)

# Generate package config files
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ZeroJSConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/ZeroJSConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ZeroJS
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/ZeroJSConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/ZeroJSConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/ZeroJSConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ZeroJS
)

# Print summary
message(STATUS "")
message(STATUS "ZeroJS ${PROJECT_VERSION}")
message(STATUS "  Build examples: ${ZEROJS_BUILD_EXAMPLES}")
message(STATUS "")
