
project(utils CXX)

configure_file(include/${PROJECT_NAME}/Version.h.in Version.h @ONLY)

file(GLOB_RECURSE UTILS_HEADERS "include/*.h")
file(GLOB_RECURSE UTILS_SOURCES "src/*.cpp")

add_library(${PROJECT_NAME}
	${CMAKE_CURRENT_BINARY_DIR}/Version.h
	${UTILS_HEADERS}
	${UTILS_SOURCES}
)

target_link_libraries(${PROJECT_NAME}
	${CONAN_LIBS}
)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		$<BUILD_INTERFACE:
			${CMAKE_CURRENT_BINARY_DIR}
			${CMAKE_CURRENT_SOURCE_DIR}/include
		>
		$<INSTALL_INTERFACE:include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

cotire(${PROJECT_NAME})
