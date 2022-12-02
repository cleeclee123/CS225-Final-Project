#pragma once

#include "Airport.h"

#include <string>
#include <vector>

class Edge
{
public:
  /**
   * @brief Default Constructor of new Airline object
   *
   */
  Edge();

  /**
   * @brief Parameterized Constructor of new Airline object
   *
   * @param airline
   * @param airlineID
   * @param srcIATA
   * @param srcID
   * @param destIATA
   * @param destID
   * @param codeshare
   * @param stops
   * @param planetypes
   */
  Edge(std::string airline, std::string airlineID, std::string srcIATA, std::string srcID, std::string destIATA, std::string destID, bool codeshare, int stops, std::string planeTypes);

  /**
   * helper function to print airline data
   * @return void like my soul
   */
  void printEdge();

  // edge data members
  std::string airline_;
  std::string airlineID_;
  std::string srcIATA_;
  std::string srcID_;
  std::string destIATA_;
  std::string destID_;
  bool codeshare_;
  int stops_;
  std::string planeTypes_;

private:
};