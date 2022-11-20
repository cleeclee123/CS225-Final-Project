#include "airline.h"
#include <string>

Airline::Airline()
{
}

Airline::Airline(std::string airlineID, std::string name, std::string alias, unsigned IATA, unsigned ICAO, std::string callsign, std::string country, bool isActive) {
  airlineID_ = airlineID;
  name_ = name;
  alias_ = alias;
  IATA_ = IATA;
  ICAO_ = ICAO;
  callsign_ = callsign;
  country_ = country;
  isActive_ = isActive;
}
