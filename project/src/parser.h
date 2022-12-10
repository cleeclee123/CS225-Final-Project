#include "airline.h"
#include "airport.h"
#include "edge.h"

#include <vector>

/**
 * @brief parse airport dataset to vector of airport classes
 * 
 * @param filename 
 * @return std::vector<Airport> 
 */
std::vector<Airport> parseAirports(std::string filename);

/**
 * @brief parse airline dataset to vector of airline classes
 * 
 * @param filename 
 * @return std::vector<Airline> 
 */
std::vector<Airline> parseAirlines(std::string filename);

/**
 * @brief parse routes dataset to vector of route classes
 * 
 * @param filename 
 * @return std::vector<Edge> 
 */
std::vector<Edge> parseRoutes(std::string filename);

/**
 * @brief helper function that splits a string by a delimiter
 * 
 * @param line 
 * @param delimiter 
 * @return std::vector<std::string> 
 */
std::vector<std::string> split(std::string line, char delimiter);