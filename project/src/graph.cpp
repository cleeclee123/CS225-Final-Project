#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "graph.h"
#include "airport.h"

Graph::Graph(std::vector<Airport> airports, std::vector<Airline> airlines, std::vector<Edge> routes)
{
  airports_ = airports;
  airlines_ = airlines;
  routes_ = routes;
  if (routes_.empty())
  {
    for (const auto &airport : airports)
    {
      adjList_.insert({airport, std::vector<Edge>()});
    }
  }
}

void Graph::addEdge(Airport from, Airport to, Edge current)
{
  if (adjList_.find(from) == adjList_.end())
  {
    addAirport(from);
  }
  else
  {
    adjList_[from].push_back(current);
  }
}

void Graph::addAirport(Airport airport)
{
  adjList_[airport] = std::vector<Edge>();
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

void Graph::buildGraph()
{
  for (const auto &route : routes_)
  {
    Airport src = this->getAirportByIATA(route.srcIATA_);
    Airport dest = this->getAirportByIATA(route.destIATA_);
    this->addEdge(src, dest, route);
  }
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

int Graph::numConnectedComponents()
{
  std::map<Airport, bool> visited;
  for (const auto &airport : adjList_)
  {
    Airport curr = airport.first;
    visited[curr] = false;
  }
  int count = 0;
  for (const auto &airport : adjList_)
  {
    dfsHelper(airport.first, visited);
    count++;
  }
  return count;
}

void Graph::dfsHelper(Airport src, std::map<Airport, bool> &visited)
{
  visited[src] = true;
  for (const auto &edge : adjList_[src])
  {
    Airport curr = getAirportByIATA(edge.destIATA_);
    if (!visited[curr])
    {
      dfsHelper(curr, visited);
    }
  }
}
