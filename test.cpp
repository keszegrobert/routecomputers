#include <sstream>
#include <gtest/gtest.h>

#include "src/priority_queue.h"
#include "src/fibonacci_heap.h"

#include "src/graph.h"
#include "src/i_routecomputer.h"
#include "src/dijkstra.h"
#include "src/quick_dijkstra.h"
#include "src/floyd_warshall.h"
#include "src/fibonacci_dijkstra.h"
#include "src/bellmanford.h"

#include "fix_sample.h"
#include "fix_negative.h"
#include "fix_grid.h"
#include "fix_sample_floydwarshall.h"

#include "test_fibonacciheap.cpp"
#include "test_priorityqueue.cpp"

#include "test_bellmanford.cpp"
#include "test_dijkstra.cpp"
#include "test_floydwarshall.cpp"

#include "test_gridworld.cpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
