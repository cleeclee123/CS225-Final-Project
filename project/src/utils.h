#include "airport.h"
#include "airline.h"
#include <string>
#include <vector>

/**
 * Get the Airport By IATA string. For graph construction
 * 
 * @param IATA 
 * @return corresponding Airport based on IATA
 */
Airport getAirportByIATA(std::vector<Airport> airports, std::string IATA);

/**
 * Get the Airline By IATA string. For graph construction
 * 
 * @param IATA 
 * @return corresponding Airline based on IATA
 */
Airline getAirlineByIATA(std::vector<Airline> airlines, std::string IATA);