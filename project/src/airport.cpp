#include "airport.h"
#include <string>
#include <cmath>

Airport::Airport()
{
}

Airport::Airport(std::string airportID,
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
                 std::string type)
{
  airportID_ = airportID;
  airportName_ = airportName;
  cityName_ = cityName;
  country_ = country;
  IATA_ = IATA;
  ICAO_ = ICAO;
  latitude_ = latitude;
  longitude_ = longitude;
  altitude_ = altitude;
  timezone_ = timezone;
  dst_ = dst;
  tz_ = tz;
  type_ = type;
}

long double Airport::toKilometers(const long double distance)
{
  // Radius of Earth in Kilometers
  long double kR = 6371;
  return distance * kR;
}

long double Airport::toMiles(const long double distance)
{
  // Radius of Earth in Miles
  long double kR = 3956;
  return distance * kR;
}

long double Airport::toRadians(const long double degrees)
{
  const long double kPI = 3.141592653589793238463;
  return (kPI / 180) * degrees;
}

unsigned Airport::distance(Airport airport)
{
  long double lat1 = toRadians(latitude_);
  long double long1 = toRadians(longitude_);
  long double lat2 = toRadians(airport.latitude_);
  long double long2 = toRadians(airport.longitude_);

  // Haversine Formula
  long double dlong = long2 - long1;
  long double dlat = lat2 - lat1;

  long double dist = std::pow(std::sin(dlat / 2), 2) + std::cos(lat1) * std::cos(lat2) * std::pow(std::sin(dlong / 2), 2);
  dist = 2 * std::asin(std::sqrt(dist));

  return toKilometers(dist);
}