#include "graph.h"
#include "airport.h"

#include <queue>

/**
 * @brief runs dijkstra's on graph, priority queue implementation
 * 
 * @param graph, passed in graph object (already built)
 * @param from, src airport
 * @param to, dest airport
 * @return a vector of the shortest path from src to dest along with their respective distances
 */
std::vector<std::pair<Airport, double>> Dijkstra(Graph graph, Airport from, Airport to);