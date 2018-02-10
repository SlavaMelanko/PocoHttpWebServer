
project(tests CXX)

include(CTest)

list(APPEND CATCH_CMAKE_ARGS
	"-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/external"
	"-DNO_SELFTEST=true"
)

# Add catch library as an external project.
externalproject_add(
	catch
	# Root dir for entire project.
	PREFIX ${CMAKE_BINARY_DIR}/catch
	# URL of git repo.
	GIT_REPOSITORY https://github.com/catchorg/Catch2.git
	# Git branch name, commit id or tag.
	GIT_TAG v2.1.2
	# Force Git to output progress information during the clone step.
	GIT_PROGRESS 1
	# Arguments to CMake command line.
	CMAKE_ARGS ${CATCH_CMAKE_ARGS}
	# Wrap download in script to log output.
	LOG_DOWNLOAD 1
	# Never update automatically from the remote repository.
	UPDATE_DISCONNECTED 1
)

include_directories(catch-lib
	${CMAKE_BINARY_DIR}/external/include
)

add_library(catch-lib STATIC Test.cpp)
add_dependencies(catch-lib catch)