#include "airline.h"
#include "airport.h"
#include <vector>

std::vector<Airport> parseAirports(std::string filename);
std::vector<Airline> parseAirlines(std::string filename);
std::vector<std::string> split(std::string line, char delimiter);