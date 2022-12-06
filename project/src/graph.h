#pragma once

#include <vector>
#include <map>
#include <string>
#include <bits/stdc++.h>

#include "airport.h"
#include "edge.h"

class Graph
{
public:
  // methods:
  /*
    // for graph construction
    - add edge
    - add vertex
    - set starting vertex
    - destructor

    // for traversals/search
    - get vertices
    - get adjacent vertices
    - get weight of edge
  */
  Graph();
  void Graph::addEdge(Airport from, Airport to, Edge current);
  void addAirport(Airport airport);
  void setStartingAirport(Airport airport);
  std::vector<Airport> getAirports();
  std::vector<Airport> getAdjacentAirports(Airport airport);
  double getWeight(Airport from, Airport to);
  double Dijkstra(Graph graph, Airport from, Airport to);
  Airport getAirportByIATA(std::string IATA);
  Airline getAirlineByIATA(std::string IATA);

private:
  Airport startingAirport_;
  std::map<Airport, std::vector<Edge>> adjList_;
  std::vector<Airport> airports_;
  std::vector<Airline> airlines_;
  std::vector<Edge> routes_;
};