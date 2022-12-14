#include "airport.h"
#include <string>
#include <cmath>
#include <iostream>

Airport::Airport()
{
}

Airport::Airport(std::string airportID,
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

bool Airport::operator==(const Airport &rhs) const
{
  return IATA_ == rhs.IATA_ && ICAO_ == rhs.ICAO_;
}

bool Airport::operator<(const Airport &rhs) const
{
  return ((std::exp(this->latitude_) * this->longitude_) <
          (std::exp(rhs.latitude_) * rhs.longitude_));
}

bool Airport::operator>(const Airport &rhs) const
{
  return ((std::exp(this->latitude_) * this->longitude_) >
          (std::exp(rhs.latitude_) * rhs.longitude_));
}

std::string Airport::getAirportID() const
{
  return airportID_;
}

std::string Airport::getAirportName() const
{
  return airportName_;
}

std::string Airport::getCityName() const
{
  return cityName_;
}

std::string Airport::getCountry() const
{
  return country_;
}

std::string Airport::getIATA() const
{
  return IATA_;
}

std::string Airport::getICAO() const
{
  return ICAO_;
}

double Airport::getLatitude() const
{
  return latitude_;
}

double Airport::getLongitude() const
{
  return longitude_;
}

unsigned Airport::getAltitude() const
{
  return altitude_;
}

std::string Airport::getTimezone() const
{
  return timezone_;
}

std::string Airport::getDst() const
{
  return dst_;
}

std::string Airport::getTz() const
{
  return tz_;
}

std::string Airport::getType() const
{
  return type_;
}

void Airport::printAirport()
{
  std::cout << "airport id: " << airportID_ << std::endl;
  std::cout << "airport name: " << airportName_ << std::endl;
  std::cout << "city name: " << cityName_ << std::endl;
  std::cout << "country: " << country_ << std::endl;
  std::cout << "IATA: " << IATA_ << std::endl;
  std::cout << "ICAO: " << ICAO_ << std::endl;
  std::cout << "latitude: " << latitude_ << std::endl;
  std::cout << "longitude: " << longitude_ << std::endl;
  std::cout << "altitude: " << altitude_ << std::endl;
  std::cout << "timezone: " << timezone_ << std::endl;
  std::cout << "dst: " << dst_ << std::endl;
  std::cout << "tz: " << tz_ << std::endl;
  std::cout << "type: " << type_ << std::endl;
}