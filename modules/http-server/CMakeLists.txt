
cmake_minimum_required(VERSION 3.10)

project(server LANGUAGES CXX)

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
            /EHsc /MP /W3 /Zf>
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
            -pipe -march=native -O0 -Wall -Werror -Wextra>
)

target_link_libraries(${PROJECT_NAME}
    ${CONAN_LIBS}
    smela::utils
)

#cotire(${PROJECT_NAME})
