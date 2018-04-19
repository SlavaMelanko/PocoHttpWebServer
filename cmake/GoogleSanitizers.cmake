
# Google Sanitizers (https://github.com/google/sanitizers)
# --------------------
#
# Dynamic testing tools for C/C++:
# - AddressSanitizer (ASan) is a fast memory error detector. It finds use-after-free
#   and {heap,stack,global}-buffer overflow bugs in C/C++ programs.
# - ThreadSanitizer (TSan) is a fast data race detector for C/C++ programs.
# - MemorySanitizer (MSan) is a fast LLVM-based tool that detects the use of uninitialized memory.
# These tools are based on compiler instrumentation (LLVM and GCC),
# which makes them very fast (e.g. ASan incurs just 2x slowdown).
#

if (NOT DEFINED ENABLE_ASAN)
    message(WARNING "Please set ENABLE_ASAN variable as true in order to use Google Sanitizers")
    return()
endif ()

if (WIN32)
    message(WARNING "Please note, there is no Windows support for Google Sanitizers")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=gold")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")

    message(STATUS "${CMAKE_CXX_FLAGS}")
endif ()
