
# Clang-Tidy
# --------------------
#
# clang-tidy is a clang-based C++ “linter” tool.
# Its purpose is to provide an extensible framework for diagnosing
# and fixing typical programming errors, like style violations,
# interface misuse, or bugs that can be deduced via static analysis.
# clang-tidy is modular and provides a convenient interface for writing new checks.
#

if (NOT ENABLE_CLANG_TIDY)
	return ()
endif ()

if (MSVC)
	message(WARNING "There is no Windows support")
else ()
	set(CLANG_TIDY_VERSION "6.0")

	find_program(CLANG_TIDY_BIN clang-tidy-${CLANG_TIDY_VERSION})

	if (CLANG_TIDY_BIN STREQUAL "CLANG_TIDY_BIN-NOTFOUND")
		message(FATAL_ERROR "Unable to locate clang-tidy-${CLANG_TIDY_VERSION}")
	endif ()

	find_program(RUN_CLANG_TIDY_BIN run-clang-tidy-${CLANG_TIDY_VERSION}.py)

	if (RUN_CLANG_TIDY_BIN STREQUAL "RUN_CLANG_TIDY_BIN-NOTFOUND")
		message(FATAL_ERROR "Unable to locate run-clang-tidy-${CLANG_TIDY_VERSION}.py")
	endif ()

	list(APPEND RUN_CLANG_TIDY_BIN_ARGS
		-clang-tidy-binary ${CLANG_TIDY_BIN}
		-header-filter='../modules'
		-checks=clan*,cert*,misc*,perf*,cppc*,read*,mode*,-cert-err58-cpp,-misc-noexcept-move-constructor
	)

	add_custom_target(tidy
		COMMAND ${RUN_CLANG_TIDY_BIN} ${RUN_CLANG_TIDY_BIN_ARGS}
		COMMENT "Running clang-tidy"
	)
endif ()
