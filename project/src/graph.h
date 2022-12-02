#pragma once

#include <vector>
#include <map>
#include <string>

#include "airport.h"

struct Edge {
  Airport from_;
  Airport to_;
  std::string uid_ = from_.IATA_ + to_.IATA_;
  double distance = from_.distance(to_);
};

class Graph {
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
    void addEdge(Airport from, Airport to);
    void addAirport(Airport airport);
    void setStartingAirport(Airport airport);
    std::vector<Airport> getAirports();
    std::vector<Airport> getAdjacentAirports(Airport airport);
    double getWeight(Airport from, Airport to);

  private: 
    Airport startingAirport_;
    std::map<Airport, std::map<Airport, Edge>> adjList_;
};