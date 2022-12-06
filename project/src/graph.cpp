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
    if (std::find(adjList_.begin(), adjList_.end(), from) == adjList_.end()) {
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

double Graph::Dijkstra(Graph graph, Airport from, Airport to) {
    std::priority_queue<std::pair<double, Airport>, std::vector<std::pair<double, Airport>>, std::greater<std::pair<double, Airport>>> pq;
    std::map<Airport, double> dist;
    std::vector<Airport> airports = graph.getAirports();
    for (auto it = airports.begin(); it != airports.end(); it++) {
        dist[*it] = INT_MAX;
    }
    dist[from] = 0;
    pq.push(std::make_pair(0, from));
    while (!pq.empty()) {
        Airport u = pq.top().second;
        pq.pop();
        std::vector<Airport> adj = graph.getAdjacentAirports(u);
        for (auto it = adj.begin(); it != adj.end(); it++) {
            Airport v = *it;
            double weight = graph.getWeight(u, v);
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(std::make_pair(dist[v], v));
            }
        }
    }
    return dist[to];
}

