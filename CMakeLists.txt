# How to build:
# mkdir build
# cd build
# cmake .. -G "Unix Makefiles"

cmake_minimum_required(VERSION 2.8)
project ( routecomp )
set(TASIM_VERSION 1.0.0)
set(GTEST_DIR "../googletest-read-only/include")

set(GTEST_HEADERS $(GTEST_DIR)/gtest/*.h
				$(GTEST_DIR)/gtest/internal/*.h)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror -I$(GTEST_DIR)")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX /EHsc")
endif()
if (NOT CONFIGURED_ONCE)
    set(CMAKE_CXX_FLAGS "${warnings}"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
    set(CMAKE_C_FLAGS   "${warnings}"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

include_directories( ./src ./tests ${GTEST_DIR})

set(HEADERS
		"src/graph.h"
		"src/i_routecomputer.h"
        "src/fibonacci_heap.h"
		"src/priority_queue.h"
        "src/bellmanford.h"
        "src/floyd_warshall.h"
        "src/dijkstra.h"
        "src/quick_dijkstra.h"
        "src/fibonacci_dijkstra.h"
)

set (FIXTURES
        "tests/fix_grid.h"
        "tests/fix_negative.h"
        "tests/fix_sample.h"
        "tests/fix_sample_floydwarshall.h"
)

add_library(routecomp_core STATIC ${HEADERS})

SET_TARGET_PROPERTIES(routecomp_core PROPERTIES LINKER_LANGUAGE CXX)

add_executable(test_routecomp test.cpp ${HEADERS} ${FIXTURES})
target_link_libraries(test_routecomp gtest gtest_main pthread routecomp_core)

set(CONFIGURED_ONCE TRUE CACHE INTERNAL
    "A flag showing that CMake has configured at least once.")
