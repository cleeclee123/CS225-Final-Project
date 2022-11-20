#pragma once

#include <string>
#include <vector>

class Airline
{
public:
  /**
   * @brief Default Constructor of new Airline object
   *
   */
  Airline();

  /**
   * @brief Parameterized Constructor of new Airline object
   * 
   * @param airlineID 
   * @param name 
   * @param alias 
   * @param IATA 
   * @param ICAO 
   * @param callsign 
   * @param country 
   * @param isActive 
   */
  Airline(std::string airlineID, std::string name, std::string alias, unsigned IATA, unsigned ICAO, std::string callsign, std::string country, bool isActive);

private:
  std::string airlineID_;
  std::string name_;
  std::string alias_;
  unsigned IATA_;
  unsigned ICAO_;
  std::string callsign_;
  std::string country_;
  bool isActive_;
};