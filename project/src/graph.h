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
   * @brief Get the Starting Airport object
   * 
   * @param airport 
   * @return Airport 
   */
  Airport getStartingAirport();

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
   * @brief gets the edge between the two passed in airport objects, if it exists
   *        if no edge exists, return empty edge, works solely on adjancent airports
   *        to be used as a helper function for shortest path traversals/searching
   * @param src
   * @param dest
   * @return edge object between the two passed in airports
   */
  // Edge getEdge(Airport src, Airport dest);
  std::vector<Edge> getEdge(Airport src, Airport dest);

  /**
   * @brief prints the graph in a pretty way
   *
   */
  void printGraph();

  /**
   * @brief counts number of connect components in the graph, works for undirected only, used in testing/building test cases
   *
   * @return size_t number of connect components in the graaph
   */
  size_t countConnectedComponents();

  /**
   * runs dfs on adj list 
   * 
   * @param v 
   */
  void dfs(Airport v);

  /**
   * @brief clears the private member data for dfs traversal
   * 
   */
  void clearTraversal();

  /**
   * determines if src is in the same componenet as dest /
   * used in testing/building test cases
   * 
   * how it works: uses dfs to determine if a path exists between two airports
   * the in_ map tracks when we first visit the airport, the out map tracks if 
   * we visit the airport again when there are no children/other airports in the path
   * reference: https://www.geeksforgeeks.org/check-if-two-nodes-are-on-same-path-in-a-tree/
   * 
   * @param src 
   * @param dest 
   * @return true
   */
  bool inComponent(Airport src, Airport dest);

  /**
   * @brief getter for dfsPath_
   * 
   * @return vector of airports from dfs traversal
   */
  std::vector<Airport> getDFSpath();

private:
  // private data members
  std::map<Airport, std::vector<Edge>> adjList_;
  Airport startingAirport_;
  std::vector<Airport> airports_;
  std::vector<Airline> airlines_;
  std::vector<Edge> routes_;
  std::map<Airport, bool> visited_;
  std::map<Airport, int> in_;
  std::map<Airport, int> out_;
  int count_;
  std::vector<Airport> dfsPath_;
};