#pragma once

#include "airport.h"

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

  /**
   * comparison operator== for airline
   * @param rhs 
   * @return bool if edge is equal to each other 
   */
  bool operator==(const Edge& rhs) const;

  /**
   * @brief Get the Airline object
   *
   * @return std::string
   */
  std::string getAirline() const;

  /**
   * @brief Get the Airline ID object
   *
   * @return std::string
   */
  std::string getAirlineID() const;

  /**
   * @brief Get the Src IATA object
   *
   * @return std::string
   */
  std::string getSrcIATA() const;

  /**
   * @brief Get the Src ID object
   *
   * @return std::string
   */
  std::string getSrcID() const;

  /**
   * @brief Get the Dest IATA object
   *
   * @return std::string
   */
  std::string getDestIATA() const;  

  /**
   * @brief Get the Dest ID object
   *
   * @return std::string
   */
  std::string getDestID() const;

  /**
   * @brief Get the Codeshare object
   *
   * @return bool
   */
  bool getCodeshare() const;

  /**
   * @brief Get the Stops object
   *
   * @return int
   */
  int getStops() const;

  /**
   * @brief Get the Plane Types object
   *
   * @return std::string
   */
  std::string getPlaneTypes() const;

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