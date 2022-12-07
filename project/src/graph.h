#pragma once

#include <vector>
#include <map>
#include <string>

#include "airport.h"
#include "airline.h"
#include "edge.h"

class Graph
{
public:
  /**
   * @brief Construct a new Graph object
   *
   * @param airports
   * @param airlines
   * @param routes_
   */
  Graph(std::vector<Airport> airports, std::vector<Airline> airlines, std::vector<Edge> routes_);

  /**
   * @brief adds an edge object to adjacency list from src and dest airports
   *
   * @param from
   * @param to
   * @param current
   */
  void addEdge(Airport from, Airport to, Edge current);

  /**
   * @brief if airport doesnt exist in graph, adds new vertex
   *
   * @param airport
   */
  void addAirport(Airport airport);

  /**
   * @brief Set the Starting Airport object
   *
   * @param airport
   */
  void setStartingAirport(Airport airport);

  /**
   * @brief Get the Airports object
   *
   * @return std::vector<Airport>
   */
  std::vector<Airport> getAirports();

  /**
   * @brief Get the Adjacent Airports object
   *
   * @param airport
   * @return std::vector<Airport>
   */
  std::vector<Airport> getAdjacentAirports(Airport airport);

  /**
   * @brief Get the distance between two airport object
   *
   * @param from
   * @param to
   * @return double
   */
  double getWeight(Airport from, Airport to);

  /**
   * @brief Get the Airport By IATA object
   *
   * @param IATA
   * @return Airport object with corresponding iata
   */
  Airport getAirportByIATA(std::string IATA);

  /**
   * @brief Get the Airline By IATA object
   *
   * @param IATA
   * @return Airline object with corresponding iata
   */
  Airline getAirlineByIATA(std::string IATA);

  /**
   * @brief prints the graph in a pretty way
   *
   */
  void printGraph();

  /**
   * @brief counts number of connect components in the graph, works for undirected only
   *
   * @return size_t number of connect components in the graaph
   */
  size_t countConnectedComponents();

private:
  // private data members
  std::map<Airport, std::vector<Edge>> adjList_;
  Airport startingAirport_;
  std::vector<Airport> airports_;
  std::vector<Airline> airlines_;
  std::vector<Edge> routes_;
};