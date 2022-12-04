#include "utils.h"
#include "airport.h"
#include "airline.h"
#include <string>

Airport getAirportByIATA(std::vector<Airport> airports, std::string IATA)
{
  for (const auto &airport : airports)
  {
    if (airport.IATA_ == IATA)
    {
      return airport;
    }
  }
  return Airport();
}

Airline getAirlineByIATA(std::vector<Airline> airlines, std::string IATA)
{
  for (const auto &airline : airlines)
  {
    if (airline.IATA_ == IATA)
    {
      return airline;
    }
  }
  return Airline();
}