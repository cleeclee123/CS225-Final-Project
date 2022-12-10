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
          std::string IATA,
          std::string ICAO,
          double latitude,
          double longitude,
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

  /**
   * helper function to print out airport data
   * @return nothing like my soul
   */
  void printAirport();

  /**
   * comparison operator== for airport
   * @param rhs 
   * @return bool if airport is equal to each other 
   */
  bool operator==(const Airport& rhs) const;

  /**
   * @brief 
   * 
   * @param rhs 
   * @return bool is this airport to other 
   */
  bool operator<(const Airport &rhs) const;

  bool operator>(const Airport &rhs) const;

  /**
   * @brief Get the Airport ID object
   *
   * @return std::string
   */
  std::string getAirportID() const;

  /**
   * @brief Get the Airport Name object
   *
   * @return std::string
   */
  std::string getAirportName() const;

  /**
   * @brief Get the City Name object
   *
   * @return std::string
   */
  std::string getCityName() const;

  /**
   * @brief Get the Country object
   *
   * @return std::string
   */
  std::string getCountry() const;

  /**
   * @brief Get the IATA object
   *
   * @return std::string
   */
  std::string getIATA() const;

  /**
   * @brief Get the ICAO object
   *
   * @return std::string
   */
  std::string getICAO() const;

  /**
   * @brief Get the Latitude object
   *
   * @return double
   */
  double getLatitude() const;

  /**
   * @brief Get the Longitude object
   *
   * @return double
   */
  double getLongitude() const;

  /**
   * @brief Get the Altitude object
   *
   * @return unsigned
   */
  unsigned getAltitude() const;

  /**
   * @brief Get the Timezone object
   *
   * @return std::string
   */
  std::string getTimezone() const;

  /**
   * @brief Get the Dst object
   *
   * @return std::string
   */
  std::string getDst() const;

  /**
   * @brief Get the Tz object
   *
   * @return std::string
   */
  std::string getTz() const;

  /**
   * @brief Get the Type object
   *
   * @return std::string
   */
  std::string getType() const;



private:
  // private helper functions
  long double toKilometers(const long double distance);
  long double toMiles(const long double distance);
  long double toRadians(const long double degrees);

  // data members
  std::string airportID_;
  std::string airportName_;
  std::string cityName_;
  std::string country_;
  std::string IATA_;
  std::string ICAO_;
  double latitude_;
  double longitude_;
  unsigned altitude_;
  std::string timezone_;
  std::string dst_;
  std::string tz_;
  std::string type_;
};