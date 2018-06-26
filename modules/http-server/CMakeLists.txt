
cmake_minimum_required(VERSION 3.10)

project(server LANGUAGES CXX)

#set(PROMETHEUS_INCLUDE_DIR "/Users/smelanko/Development/Projects/prometheus-cpp/include/prometheus")
#set(PROMETHEUS_LIBRARY "/Users/smelanko/Development/Projects/prometheus-cpp/_build/lib/libprometheus-cpp.a")

configure_file(src/Version.h.in Version.h @ONLY)

file(GLOB_RECURSE ${PROJECT_NAME}_HEADERS "src/*.h")
file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME}
    ${${PROJECT_NAME}_SOURCES}
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)
target_compile_options(${PROJECT_NAME}
    PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:
            /MP /W3 /Zf
            $<$<CONFIG:Debug>:/MTd>
            $<$<CONFIG:Release>:/MT>>
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
            -Wall -Wextra -Werror -Wpedantic -pedantic-errors -pipe>
)

#target_include_directories(${PROJECT_NAME}
#    PUBLIC
#        ${PROMETHEUS_INCLUDE_DIR}
#)

target_link_libraries(${PROJECT_NAME}
    ${CONAN_LIBS}
    smela::utils
#    ${PROMETHEUS_LIBRARY}
)
