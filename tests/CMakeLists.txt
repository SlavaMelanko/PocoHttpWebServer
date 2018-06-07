
project(tests CXX)

list(APPEND CATCH_CMAKE_ARGS
    "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/external"
    "-DBUILD_TESTING=OFF"
)

# Add catch library as an external project.
externalproject_add(
    catch
    # Root dir for entire project.
    PREFIX ${CMAKE_BINARY_DIR}/catch
    # URL of git repo.
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    # Git branch name, commit id or tag.
    GIT_TAG v2.2.2
    # Arguments to CMake command line.
    CMAKE_ARGS ${CATCH_CMAKE_ARGS}
)

# Build catch2 as library file to avoid slow compilation for each test.
set(CATCH2_LIB catch2)
add_library(${CATCH2_LIB} STATIC Test.cpp)
add_library(smela::catch2 ALIAS ${CATCH2_LIB})
target_include_directories(${CATCH2_LIB}
    PUBLIC
        ${CMAKE_BINARY_DIR}/external/include
)
add_dependencies(${CATCH2_LIB} catch)

function(do_test name)
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name}
        smela::catch2
        utils
    )
    add_dependencies(${name} catch)
    add_test(${name} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${name})
    # Group all tests under tests directory.
    set_property(TARGET ${name} PROPERTY FOLDER "tests")
endfunction()

do_test(ChronoTest)
