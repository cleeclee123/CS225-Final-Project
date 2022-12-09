#include "iddfs.h"


std::vector<Airport> IDDFS(Graph g, Airport from, Airport to, unsigned int max_depth, std::map<Airport, Airport>& previous) {
    bool found = false;
    for (unsigned int i = 0; i <= max_depth; i++) {
        if (DLS(g, from, to, i, previous)) {
            found = true;
            break;
        }
    }
    if (!found) return std::vector<Airport>();
    std::vector<Airport> path;
    Airport current = to;
    while (current.airportID_ != from.airportID_) {
        path.push_back(current);
        current = previous[current];
    }
    path.push_back(from);
    return path;
}

bool DLS(Graph g, Airport from, Airport to, int limit, std::map<Airport, Airport>& previous) {
    if (from == to) return true;
    if (limit <= 0) return false;  
    std::vector<Airport> adj = g.getAdjacentAirports(from);
    for (auto it = adj.begin(); it != adj.end(); it++) {
        previous[*it] = from;
        if (DLS(g, *it, to, limit - 1, previous)) return true;
    }

    return false;
}
