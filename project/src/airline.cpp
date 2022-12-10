#include "airline.h"
#include <string>
#include <iostream>

Airline::Airline()
{
}

Airline::Airline(std::string airlineID, std::string name, std::string alias, std::string IATA, std::string ICAO, std::string callsign, std::string country, bool isActive)
{
  airlineID_ = airlineID;
  name_ = name;
  alias_ = alias;
  IATA_ = IATA;
  ICAO_ = ICAO;
  callsign_ = callsign;
  country_ = country;
  isActive_ = isActive;
}

bool Airline::operator==(const Airline &rhs) const
{
  return IATA_ == rhs.IATA_ && ICAO_ == rhs.ICAO_;
}

void Airline::printAirline()
{
  std::cout << "airline id: " << airlineID_ << std::endl;
  std::cout << "name: " << name_ << std::endl;
  std::cout << "alias: " << alias_ << std::endl;
  std::cout << "IATA: " << IATA_ << std::endl;
  std::cout << "ICAO: " << ICAO_ << std::endl;
  std::cout << "callsign: " << callsign_ << std::endl;
  std::cout << "country: " << country_ << std::endl;
  std::cout << "isActive status: " << isActive_ << std::endl;
}

std::string Airline::getAirlineID() const
{
  return airlineID_;
}

std::string Airline::getName() const
{
  return name_;
}

std::string Airline::getAlias() const
{
  return alias_;
}

std::string Airline::getIATA() const
{
  return IATA_;
}

std::string Airline::getICAO() const
{
  return ICAO_;
}

std::string Airline::getCallsign() const
{
  return callsign_;
}

std::string Airline::getCountry() const
{
  return country_;
}

bool Airline::getIsActive() const
{
  return isActive_;
}