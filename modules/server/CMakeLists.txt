
cmake_minimum_required(VERSION 3.8.2)

project(server CXX)

configure_file(src/Version.h.in Version.h @ONLY)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME}
	${CMAKE_CURRENT_BINARY_DIR}/Version.h
	${SOURCES}
)

message(STATUS "${CONAN_LIBS}")

target_link_libraries(${PROJECT_NAME}
	${CONAN_LIBS}
)

cotire(${PROJECT_NAME})
