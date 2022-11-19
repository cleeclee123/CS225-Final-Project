#pragma once

#include <string>

class Airport
{
public:
  Airport();
  Airport(std::string airportName, std::string country, unsigned IATA, unsigned latitude, unsigned longitude);
  unsigned distance(Airport airport);

private:
  std::string airportName_;
  std::string country_;
  unsigned IATA_;
  unsigned latitude_;
  unsigned longitude_;
};