#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>

#include "graph.h"
#include "airport.h"

Graph::Graph(std::vector<Airport> airports, std::vector<Airline> airlines, std::vector<Edge> routes)
{
  airports_ = airports;
  airlines_ = airlines;
  routes_ = routes;

  for (const auto &airport : airports)
  {
    adjList_.insert({airport, std::vector<Edge>()});
  }
  for (const auto &route : routes_)
  {
    Airport src = this->getAirportByIATA(route.srcIATA_);
    Airport dest = this->getAirportByIATA(route.destIATA_);
    this->addEdge(src, dest, route);
  }
}

void Graph::addEdge(Airport from, Airport to, Edge current)
{
  // first condition is redunant because we push all push into adjacency list in constructor
  if (adjList_.find(from) == adjList_.end())
  {
    addAirport(from);
    adjList_[from].push_back(current);
  }
  else
  {
    adjList_[from].push_back(current);
  }
}

// this function is redunant because we push all push into adjacency list in constructor
void Graph::addAirport(Airport airport)
{
  adjList_.insert({airport, std::vector<Edge>()});
  // adjList_[airport] = std::vector<Edge>();
}

void Graph::setStartingAirport(Airport airport)
{
  startingAirport_ = airport;
}

std::vector<Airport> Graph::getAirports()
{
  std::vector<Airport> airports;
  for (auto it = adjList_.begin(); it != adjList_.end(); it++)
  {
    airports.push_back(it->first);
  }
  return airports;
}

std::vector<Airport> Graph::getAdjacentAirports(Airport airport)
{
  std::vector<Airport> airports;
  for (auto it = adjList_[airport].begin(); it != adjList_[airport].end(); it++)
  {
    airports.push_back(getAirportByIATA(it->destIATA_));
  }
  return airports;
}

double Graph::getWeight(Airport from, Airport to)
{
  return from.distance(to);
}

Airport Graph::getAirportByIATA(std::string IATA)
{
  for (const auto &airport : airports_)
  {
    if (airport.IATA_ == IATA)
    {
      return airport;
    }
  }
  return Airport();
}

Airline Graph::getAirlineByIATA(std::string IATA)
{
  for (const auto &airline : airlines_)
  {
    if (airline.IATA_ == IATA)
    {
      return airline;
    }
  }
  return Airline();
}

void Graph::printGraph()
{
  for (auto it = adjList_.cbegin(); it != adjList_.cend(); ++it)
  {
    std::cout << it->first.airportName_ << " : edges => ";
    for (const auto &edge : it->second)
    {
      std::cout << "source: " << edge.srcIATA_ << " dest: " << edge.destIATA_ << " , ";
    }
    std::cout << std::endl;
  }
}

size_t Graph::countConnectedComponents()
{
  size_t count = 0;
  bool traversed = false;
  std::map<Airport, bool> checked;
  for (std::pair<Airport, std::vector<Edge>> pair : adjList_)
  {
    checked.insert(std::pair<Airport, bool>(pair.first, false));
  }
  Airport start;
  while (!traversed)
  {
    traversed = true;
    for (std::pair<Airport, bool> pair : checked)
    {
      if (!pair.second)
      {
        start = pair.first;
        traversed = false;
      }
    }
    if (traversed)
    {
      break;
    }
    std::queue<Airport> queue;
    queue.push(start);
    checked.find(start)->second = true;

    while (!queue.empty())
    {
      std::vector<Airport> adj = getAdjacentAirports(queue.front());
      for (auto const &vertex : adj)
      {
        if (!checked.find(vertex)->second)
        {
          queue.push(vertex);
          checked.find(vertex)->second = true;
        }
      }
      queue.pop();
    }
    count += 1;
  }
  return count;
}

std::vector<Edge> Graph::getEdge(Airport src, Airport dest)
{
  std::vector<Edge> edges;
  for (auto itm = adjList_.cbegin(); itm != adjList_.cend(); itm++)
  {
    if (itm->first == src) {
      for (const auto& edge : itm->second) {
        if (edge.destIATA_ == dest.IATA_) {
          edges.push_back(edge);
        }
      }
    }
  }
  return edges;
}

void Graph::dfs(Airport v) {
    // update visited map
  std::map<Airport, bool>::iterator itv = visited_.find(v);
  if (itv != visited_.end()) {
    itv->second = true;
  }

  // recursion for v, entry time
  count_++;
  std::cout << count_ << std::endl;

  // update in time map
  std::map<Airport, int>::iterator iti = in_.find(v);
  if (iti != in_.end()) {
    iti->second = count_;
  }

  std::vector<Edge>::iterator ite = adjList_[v].begin();
  while (ite != adjList_[v].end()) {
    std::cout << getAirportByIATA(ite->destIATA_).IATA_ << std::endl;
    if (visited_[getAirportByIATA(ite->destIATA_)] == false) {
      dfs(getAirportByIATA(ite->destIATA_));
    }
    ite++;
  }

  // recursion for v, exit time
  count_++;
  std::cout << count_ << std::endl;

  // update out time map
  std::map<Airport, int>::iterator ito = out_.find(v);
  if (ito != out_.end()) {
    ito->second = count_;
  }
}

bool Graph::inComponent(Airport src, Airport dest) {
  return ( (in_[src] < in_[dest] && out_[src] > out_[dest]) ||
             (in_[src] < in_[dest] && out_[src] > out_[dest]) );
}