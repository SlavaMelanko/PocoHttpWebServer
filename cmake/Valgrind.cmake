
# Valgrind (http://valgrind.org)
# --------------------
#
# Valgrind is an instrumentation framework for building dynamic analysis tools. There are
# Valgrind tools that can automatically detect many memory management and threading bugs,
# and profile your programs in detail. You can also use Valgrind to build new tools.
#

if (NOT ENABLE_VALGRIND)
    message(WARNING "Please set ENABLE_VALGRIND variable as true in order to use Valgrind")
    return()
endif ()

if (WIN32)
    message(WARNING "Please note, there is no Windows support for Valgrind")
else ()
    # Give details for each definitely lost or possibly lost block, including where it was allocated.
    set(MEMORYCHECK_COMMAND_OPTIONS "--leak-check=full")
    # Print out a list of open file descriptors on exit or on request, via the gdbserver monitor
    # command v.info open_fds. Along with each file descriptor is printed a stack backtrace of
    # where the file was opened and any details relating to the file descriptor.
    set(MEMORYCHECK_COMMAND_OPTIONS "${MEMORYCHECK_COMMAND_OPTIONS} --track-fds=yes")
    # Trace into sub-processes initiated via the exec system call.
    # This is necessary for multi-process programs.
    set(MEMORYCHECK_COMMAND_OPTIONS "${MEMORYCHECK_COMMAND_OPTIONS} --trace-children=yes")
    # Specifies an alternative exit code to return if Valgrind reported any errors in the run.
    set(MEMORYCHECK_COMMAND_OPTIONS "${MEMORYCHECK_COMMAND_OPTIONS} --error-exitcode=1")

    message(STATUS "Command-line options to the \"${MEMORYCHECK_COMMAND}\" tool is "
        "\"${MEMORYCHECK_COMMAND_OPTIONS}\"")
endif ()

