
project(utils CXX)

configure_file(include/${PROJECT_NAME}/Version.h.in Version.h @ONLY)

file(GLOB_RECURSE ${PROJECT_NAME}_HEADERS "include/*.h")
file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES "src/*.cpp")

add_library(${PROJECT_NAME}
    ${CMAKE_CURRENT_BINARY_DIR}/Version.h
    ${${PROJECT_NAME}_HEADERS}
    ${${PROJECT_NAME}_SOURCES}
    )

add_library(smela::utils ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}
        ${PROJECT_SOURCE_DIR}/include
    )

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${CONAN_LIBS}
    )

cotire(${PROJECT_NAME})
