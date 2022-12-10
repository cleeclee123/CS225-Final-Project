#include <queue>
#include <limits.h>
#include "dijkstra.h"

std::vector<std::pair<Airport, double>> Dijkstra(Graph graph, Airport from, Airport to) {
  //initialize dist
  std::map<Airport, double> dist;
  std::vector<Airport> airports = graph.getAirports();
  for (auto it = airports.begin(); it != airports.end(); it++) {
    dist[*it] = INT_MAX;
  }
  dist[from] = 0;
  
  //initialize previous
  std::map<Airport, Airport> previous;

  //initialize priority queue
  std::priority_queue<std::pair<double, Airport>, std::vector<std::pair<double, Airport>>, std::greater<std::pair<double, Airport>>> pq;
  pq.push(std::make_pair(0, from));
  //initialize visited
  std::map<Airport, bool> visited;
  for (auto it = airports.begin(); it != airports.end(); it++) {
    visited[*it] = false;
  }

  //while the top of the queue is not the destination
  while (pq.top().second.getAirportID() != to.getAirportID()) {
    //get the top of the queue
    Airport u = pq.top().second;
    //pop the top of the queue
    pq.pop();
    //get the adjacent airports
    std::vector<Airport> adj = graph.getAdjacentAirports(u);
    //for each adjacent airport
    for (auto it = adj.begin(); it != adj.end(); it++) {
      if (visited[*it]) continue;
      Airport v = *it;
      double weight = graph.getWeight(u, v);
      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        previous[v] = u;
        pq.push(std::make_pair(dist[v], v));
      }
    }
    //save the airport as visited
    visited[u] = true;
    if (pq.empty()) return std::vector<std::pair<Airport, double>>();
  }

  //get path from previous
  std::vector<std::pair<Airport, double>> path;
  Airport current = to;
  while (current.getAirportID() != from.getAirportID()) {
    path.push_back(std::make_pair(current, dist[current]));
    current = previous[current];
  }
  path.push_back(std::make_pair(from, dist[from]));
  return path;
}