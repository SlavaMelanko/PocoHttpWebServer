
cmake_minimum_required(VERSION 3.8.2)

project(poco-http-web-server CXX)

# Set current project version.
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

# Organize targets into folders.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Extend a list of directories specifying a search path for CMake modules
# to be loaded by the the include() or find_package() commands.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Load and run CMake code from the file given.
include(cotire)
#include(CxxCompilerOptions)
include(ExternalProject)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
# Set global include directories, libraries directories, definitions, etc.
conan_basic_setup()

if (ENABLE_COVERAGE)
    include(Coverage)
endif ()

add_subdirectory(modules/http-server)
add_subdirectory(modules/utils)

if (ENABLE_TESTING)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif ()

if (ENABLE_CPPCHECK)
    include(Cppcheck)
endif ()

if (ENABLE_CLANG_TIDY)
    include(ClangTidy)
endif ()

if (ENABLE_VALGRIND)
    include(Valgrind)
endif ()

if (ENABLE_ASAN)
    include(GoogleSanitizers)
endif ()

if (ENABLE_MSAN)
    include(GoogleSanitizers)
endif ()

if (ENABLE_TSAN)
    include(GoogleSanitizers)
endif ()

