
cmake_minimum_required(VERSION 3.10)

project(utils LANGUAGES CXX)

configure_file(include/${PROJECT_NAME}/Version.h.in Version.h @ONLY)

file(GLOB_RECURSE ${PROJECT_NAME}_HEADERS "include/*.h")
file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES "src/*.cpp")

add_library(${PROJECT_NAME}
    ${${PROJECT_NAME}_SOURCES}
)

add_library(smela::utils ALIAS ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)
target_compile_options(${PROJECT_NAME}
    PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:
            /EHsc /MP /W3 /Zf>
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
            -pipe -march=native -O0 -Wall -Werror -Wextra>
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${CONAN_LIBS}
)

#cotire(${PROJECT_NAME})
