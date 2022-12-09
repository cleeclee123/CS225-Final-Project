#include "graph.h"
#include "airport.h"
#include <queue>
#include <iostream>


std::vector<Airport> IDDFS(Graph g, Airport from, Airport to, unsigned int max_depth, std::map<Airport, Airport>& previous);

bool DLS(Graph g, Airport from, Airport to, int limit, std::map<Airport, Airport>& previous);