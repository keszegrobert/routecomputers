# routecomputers
A bunch of algorithms computing routes in the given graph

Dijkstra - computes routes using a priority queue for deciding which node to choose in the next step (one to many points)

QuickDijkstra - computes routes using a simple queue for deciding which node to choose in the next step (one to many points)

FibonacciDijkstra - computes routes using a fibonacci heap for deciding which node to choose in the next step (one to many points)

BellmanFord - this algorithm can handle edges with negative weights to compute routes (one to many points)

FloydWarshall - this algorithm can compute routes from every point to every point.

# Statistics on grids
```
GRID 10x10 nodes
-Dijkstra:1445ms
-QuickDijkstra:123ms
-FibonacciDijkstra:251ms
-BellmanFord:620ms
-FloydWarshall:111ms

GRID OF 20x20 nodes
-Dijkstra:116252ms
-QuickDijkstra:1998ms
-FibonacciDijkstra:4287ms
-BellmanFord:21662ms
-FloydWarshall:5747ms
```
