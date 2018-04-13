
# Coverage
# --------------------
#
# Code coverage is a measurement used to express which lines of code
# were executed by a test suite.
#

if (MSVC14 OR MSVC15)
	message(WARNING "Coverage does not work on Windows")
else ()
	if (ENABLE_COVERAGE)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
			-g \
			-O0 \
			-fprofile-arcs \
			-ftest-coverage"
		)
		set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} \
			--coverage"
		)
	endif ()
endif ()

