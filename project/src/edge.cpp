#include <string>
#include <iostream>

#include "edge.h"

Edge::Edge()
{
}

Edge::Edge(std::string airline, std::string airlineID, std::string srcIATA, std::string srcID, std::string destIATA, std::string destID, bool codeshare, int stops, std::string planeTypes)
{
  airline_ = airline;
  airlineID_ = airlineID;
  srcIATA_ = srcIATA;
  srcID_ = srcID;
  destIATA_ = destIATA;
  destID_ = destID;
  codeshare_ = codeshare;
  stops_ = stops;
  planeTypes_ = planeTypes;
}

bool Edge::operator==(const Edge& rhs) const {
  return srcIATA_ == rhs.srcIATA_ && srcID_ == rhs.srcIATA_ && destIATA_ == rhs.destIATA_ && destID_ == rhs.destID_;
}

std::string Edge::getAirline() const
{
  return airline_;
}

std::string Edge::getAirlineID() const
{
  return airlineID_;
}

std::string Edge::getSrcIATA() const
{
  return srcIATA_;
}

std::string Edge::getSrcID() const
{
  return srcID_;
}

std::string Edge::getDestIATA() const
{
  return destIATA_;
}

std::string Edge::getDestID() const
{
  return destID_;
}

bool Edge::getCodeshare() const
{
  return codeshare_;
}

int Edge::getStops() const
{
  return stops_;
}

std::string Edge::getPlaneTypes() const
{
  return planeTypes_;
}

void Edge::printEdge()
{
  std::cout << "airline: " << airline_ << std::endl;
  std::cout << "airline id " << airlineID_ << std::endl;
  std::cout << "source airport iata" << srcIATA_ << std::endl;
  std::cout << "source airport id " << srcID_ << std::endl;
  std::cout << "dest airport iata " << destIATA_ << std::endl;
  std::cout << "dest airport id " << destID_ << std::endl;
  std::cout << "does codeshares " << codeshare_ << std::endl;
  std::cout << "number of stops " << stops_ << std::endl;
  std::cout << "planetypes " << planeTypes_ << std::endl;
  
}