
cmake_minimum_required(VERSION 3.10)

project(ms LANGUAGES CXX)

include(ExternalProject)

set(PROMETHEUS_INSTALL_PATH "${CMAKE_BINARY_DIR}/external/prometheus")

list(APPEND PROMETHEUS_CMAKE_ARGS
    "-DCMAKE_INSTALL_PREFIX=${PROMETHEUS_INSTALL_PATH}"
)

# Add Prometheus library as an external project.
externalproject_add(
    prometheus
    # Root dir for entire project.
    PREFIX ${CMAKE_BINARY_DIR}/prometheus
    # URL of git repo.
    GIT_REPOSITORY https://github.com/jupp0r/prometheus-cpp.git
    # Git branch name, commit id or tag.
    GIT_TAG v0.4.1
    # Arguments to CMake command line.
    CMAKE_ARGS ${PROMETHEUS_CMAKE_ARGS}
)

file(GLOB_RECURSE ${PROJECT_NAME}_HEADERS "include/*.h")
file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES "src/*.cpp")

add_library(${PROJECT_NAME}
    ${${PROJECT_NAME}_SOURCES}
)

add_library(smela::ms ALIAS ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)
target_compile_options(${PROJECT_NAME}
    PRIVATE
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
            -Wall -Wextra -Werror -Wpedantic -pedantic-errors -pipe>
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${PROMETHEUS_INSTALL_PATH}/include
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${PROMETHEUS_INSTALL_PATH}/lib/libprometheus-cpp.a
)
