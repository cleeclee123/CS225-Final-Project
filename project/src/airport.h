#pragma once

#include <string>

class Airport
{
public:
  /**
   * @brief Default Constructor of new Airport object
   *
   */
  Airport();

  /**
   * @brief Parameterized Constructor of new Airport object
   *
   * @param airportID
   * @param airportName
   * @param cityName
   * @param country
   * @param IATA
   * @param ICAO
   * @param latitude
   * @param longitude
   * @param altitude
   * @param timezone
   * @param dst
   * @param tz
   * @param type
   */
  Airport(std::string airportID,
          std::string airportName,
          std::string cityName,
          std::string country,
          unsigned IATA,
          unsigned ICAO,
          unsigned latitude,
          unsigned longitude,
          unsigned altitude,
          std::string timezone,
          std::string dst,
          std::string tz,
          std::string type);

  /**
   * Calculates the distance between current airport and passed in airport using the Haversine formula
   * Reference: https://www.geeksforgeeks.org/program-distance-two-points-earth/
   *
   * @param airport
   * @return unsigned distance between two airports from lat/long in kilometers
   */
  unsigned distance(Airport airport);

private:
  // private helper functions
  long double toKilometers(const long double distance);
  long double toMiles(const long double distance);
  long double toRadians(const long double degrees);

  // private data members
  std::string airportID_;
  std::string airportName_;
  std::string cityName_;
  std::string country_;
  unsigned IATA_;
  unsigned ICAO_;
  unsigned latitude_;
  unsigned longitude_;
  unsigned altitude_;
  std::string timezone_;
  std::string dst_;
  std::string tz_;
  std::string type_;
};