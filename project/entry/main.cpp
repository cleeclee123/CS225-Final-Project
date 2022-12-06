#include <iostream>

#include "graph.h"
#include "parser.h"
#include "utils.h"

int main()
{
    std::vector<Airport> airports = parseAirports("../tests/data/airports.dat");
    std::vector<Airline> airlines = parseAirlines("../tests/data/airlines.dat");
    std::vector<Edge> routes = parseRoutes("../tests/data/routes.dat");
    
    Graph graph;
    
    for (const auto& route : routes) {
        Airport src = getAirportByIATA(airports, route.srcIATA_);
        Airport dest = getAirportByIATA(airports, route.destIATA_);
        graph.addEdge(src, dest, route);
    }

    return 0;
}