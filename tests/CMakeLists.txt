
project(tests CXX)

set(CATCH2_INSTALL_PATH "${CMAKE_BINARY_DIR}/external/catch2")

list(APPEND CATCH2_CMAKE_ARGS
    "-DCMAKE_INSTALL_PREFIX=${CATCH2_INSTALL_PATH}"
    "-DBUILD_TESTING=OFF"
)

# Add Catch2 library as an external project.
externalproject_add(
    catch
    # Root dir for entire project.
    PREFIX ${CMAKE_BINARY_DIR}/catch
    # URL of git repo.
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    # Git branch name, commit id or tag.
    GIT_TAG v2.2.2
    # Arguments to CMake command line.
    CMAKE_ARGS ${CATCH2_CMAKE_ARGS}
)

# Exactly one source file must #define CATCH_CONFIG_MAIN before #include-ing Catch.
# In this file do not write any test cases! In most cases that means this file will
# just contain two lines (the #define and the #include). Keep all your test cases
# in other files. This way you will not pay the recompilation cost for all Catch.
add_library(catch2 STATIC Test.cpp)
add_library(smela::catch2 ALIAS catch2)
target_compile_features(catch2 PUBLIC cxx_std_14)
target_compile_options(catch2
    PUBLIC
        $<$<CXX_COMPILER_ID:MSVC>:
            /MP /W3 /Zf
            $<$<CONFIG:Debug>:/MTd>
            $<$<CONFIG:Release>:/MT>>
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
            -Wall -Wextra -Werror -Wpedantic -pedantic-errors -pipe>
)
target_include_directories(catch2
    PUBLIC
        ${CATCH2_INSTALL_PATH}/include
)
add_dependencies(catch2 catch)

# Performs actual test case.
function(do_test name library)
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name}
        PRIVATE
            smela::catch2
            smela::${library}
    )
    add_dependencies(${name} catch)
    add_test(NAME ${name} COMMAND $<TARGET_FILE:${name}>)
    set_property(TARGET ${name} PROPERTY FOLDER "tests")
endfunction()

do_test(ChronoTest utils)
