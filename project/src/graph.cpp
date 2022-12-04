#include "graph.h"
#include "airport.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

void Graph::addEdge(Airport from, Airport to) {
    Edge edge;
    edge.from_ = from;
    edge.to_ = to;
    edge.distance = from.distance(to);
    if (adjList_.find(from) == adjList_.end()) {
        addAirport(from);
    } 
    adjList_[from].push_back(edge);
    
}

void Graph::addAirport(Airport airport) {
    adjList_[airport] = std::vector<Edge>();
}

void Graph::setStartingAirport(Airport airport) {
    startingAirport_ = airport;
}

std::vector<Airport> Graph::getAirports() {
    std::vector<Airport> airports;
    for (auto it = adjList_.begin(); it != adjList_.end(); it++) {
        airports.push_back(it->first);
    }
    return airports;
}

std::vector<Airport> Graph::getAdjacentAirports(Airport airport) {
    std::vector<Airport> airports;
    for (auto it = adjList_[airport].begin(); it != adjList_[airport].end(); it++) {
        airports.push_back(it->to_);
    }
    return airports;
}

double Graph::getWeight(Airport from, Airport to) {
    return from.distance(to);
}

void Graph::Dijkstra(Graph graph, Airport from, Airport to) {
    
}

