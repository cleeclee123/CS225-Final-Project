#include <queue>
#include <limits.h>

#include "dijkstra.h"

double Dijkstra(Graph graph, Airport from, Airport to)
{
  std::priority_queue<std::pair<double, Airport>, std::vector<std::pair<double, Airport>>, std::greater<std::pair<double, Airport>>> pq;
  std::map<Airport, double> dist;
  std::vector<Airport> airports = graph.getAirports();
  for (auto it = airports.begin(); it != airports.end(); it++)
  {
    dist[*it] = INT_MAX;
  }
  dist[from] = 0;
  pq.push(std::make_pair(0, from));
  while (!pq.empty())
  {
    Airport u = pq.top().second;
    pq.pop();
    std::vector<Airport> adj = graph.getAdjacentAirports(u);
    for (auto it = adj.begin(); it != adj.end(); it++)
    {
      Airport v = *it;
      double weight = graph.getWeight(u, v);
      if (dist[v] > dist[u] + weight)
      {
        dist[v] = dist[u] + weight;
        pq.push(std::make_pair(dist[v], v));
      }
    }
  }
  return dist[to];
}