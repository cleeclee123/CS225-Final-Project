#include <iostream>

#include "graph.h"
#include "parser.h"

int main()
{
    std::vector<Airport> airports = parseAirports("../tests/data/airports.dat");
    std::vector<Airline> airlines = parseAirlines("../tests/data/airlines.dat");
    std::vector<Edge> routes = parseRoutes("../tests/data/routes.dat");

    Graph graph(airports, airlines);

    for (const auto &route : routes)
    {
        Airport src = graph.getAirportByIATA(route.srcIATA_);
        Airport dest = graph.getAirportByIATA(route.destIATA_);
        graph.addEdge(src, dest, route);
    }
    graph.printGraph();

    return 0;
}