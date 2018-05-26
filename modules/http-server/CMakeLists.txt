
project(server CXX)

configure_file(src/Version.h.in Version.h @ONLY)

file(GLOB_RECURSE ${PROJECT_NAME}_HEADERS "src/*.h")
file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_BINARY_DIR}/Version.h
    ${${PROJECT_NAME}_HEADERS}
    ${${PROJECT_NAME}_SOURCES}
    )

target_link_libraries(${PROJECT_NAME}
    ${CONAN_LIBS}
    smela::utils
    )

cotire(${PROJECT_NAME})
