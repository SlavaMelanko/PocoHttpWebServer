
project(server CXX)

configure_file(src/Version.h.in Version.h @ONLY)

file(GLOB_RECURSE HTTP_SERVER_HEADERS "src/*.h")
file(GLOB_RECURSE HTTP_SERVER_SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME}
	${CMAKE_CURRENT_BINARY_DIR}/Version.h
	${HTTP_SERVER_HEADERS}
	${HTTP_SERVER_SOURCES}
)

target_link_libraries(${PROJECT_NAME}
	${CONAN_LIBS}
	utils
)

cotire(${PROJECT_NAME})
