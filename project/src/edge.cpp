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

void Edge::printEdge()
{
  std::cout << "airline: " << airlineID_ << std::endl;
  std::cout << "airline id " << airlineID_ << std::endl;
  std::cout << "source airport iata" << srcIATA_ << std::endl;
  std::cout << "source airport id " << srcID_ _ << std::endl;
  std::cout << "dest airport iata " << destIATA_ _ << std::endl;
  std::cout << "dest airport id " << destID_ _ << std::endl;
  std::cout << "does codeshares " << codeshare_ _ << std::endl;
  std::cout << "number of stops " << stops_ _ << std::endl;
  std::cout << "planetypes " << planeTypes_ << std::endl;
  
}