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
    visited_.insert({airport, false});
    in_.insert({airport, -1});
    out_.insert({airport, -1});
  }
  for (const auto &route : routes_)
  {
    Airport src = this->getAirportByIATA(route.getSrcIATA());
    Airport dest = this->getAirportByIATA(route.getDestIATA());
    this->addEdge(src, dest, route);
  }
}

void Graph::addEdge(Airport from, Airport to, Edge current)
{
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

void Graph::addAirport(Airport airport)
{
  adjList_.insert({airport, std::vector<Edge>()});
}

void Graph::setStartingAirport(Airport airport)
{
  startingAirport_ = airport;
}

Airport Graph::getStartingAirport()
{
  return startingAirport_;
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
    airports.push_back(getAirportByIATA(it->getDestIATA()));
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
    if (airport.getIATA() == IATA)
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
    if (airline.getIATA() == IATA)
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
    std::cout << it->first.getAirportName() << " : edges => ";
    for (const auto &edge : it->second)
    {
      std::cout << "source: " << edge.getSrcIATA() << " dest: " << edge.getDestIATA() << " , ";
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
    if (itm->first == src)
    {
      for (const auto &edge : itm->second)
      {
        if (edge.getDestIATA() == dest.getIATA())
        {
          edges.push_back(edge);
        }
      }
    }
  }
  return edges;
}

void Graph::dfs(Airport v)
{
  // update visited map
  std::map<Airport, bool>::iterator itv = visited_.find(v);
  if (itv != visited_.end())
  {
    itv->second = true;
  }

  // recursion for v, entry time
  count_++;

  // update in time map
  std::map<Airport, int>::iterator iti = in_.find(v);
  if (iti != in_.end())
  {
    iti->second = count_;
  }

  std::vector<Edge>::iterator ite = adjList_[v].begin();
  while (ite != adjList_[v].end())
  {
    if (visited_[getAirportByIATA(ite->getDestIATA())] == false)
    {
      dfsPath_.push_back(getAirportByIATA(ite->getDestIATA()));
      dfs(getAirportByIATA(ite->getDestIATA()));
    }
    ite++;
  }

  // recursion for v, exit time
  count_++;

  // update out time map
  std::map<Airport, int>::iterator ito = out_.find(v);
  if (ito != out_.end())
  {
    ito->second = count_;
  }
}

void Graph::clearTraversal()
{
  visited_.clear();
  in_.clear();
  out_.clear();
  count_ = 0;
  dfsPath_.clear();

  // re-init 
  for (const auto &airport : airports_)
  {
    visited_.insert({airport, false});
    in_.insert({airport, -1});
    out_.insert({airport, -1});
  }
}

bool Graph::inComponent(Airport src, Airport dest)
{
  return ((in_[src] < in_[dest] && out_[src] > out_[dest]) ||
          (in_[src] < in_[dest] && out_[src] > out_[dest]));
}

std::vector<Airport> Graph::getDFSpath()
{
  return dfsPath_;
}