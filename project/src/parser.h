#include "airline.h"
#include "airport.h"
#include "edge.h"
#include <vector>

std::vector<Airport> parseAirports(std::string filename);
std::vector<Airline> parseAirlines(std::string filename);
std::vector<Edge> parseRoutes(std::string filename);
std::vector<std::string> split(std::string line, char delimiter);