#include "graph.h"
#include "airport.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

Graph::Graph(std::vector<Airport> airports, std::vector<Airline> airlines) {
    airports_ = airports;
    airlines_ = airlines;
}

void Graph::addEdge(Airport from, Airport to, Edge current)
{
    if (std::find(adjList_.begin(), adjList_.end(), from) == adjList_.end())
    {
        addAirport(from);
    }
    adjList_[from].push_back(current);
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
