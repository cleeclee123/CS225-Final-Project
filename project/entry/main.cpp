#include <iostream>
#include "dijkstra.h"
#include "IDDFS.h"
#include "graph.h"
#include "parser.h"
#include "airport.h"
#include <limits.h>
#include <queue>
#include <vector>
#include <bits/stdc++.h>

/**
 * @brief runs dijkstra on our graph, returns the shortest path that exists between two airports
 *
 * @param graph
 * @param from
 * @param to
 */
void RunDijkstra(Graph graph, Airport from, Airport to)
{
    std::vector<std::pair<Airport, double>> path = Dijkstra(graph, from, to);
    std::reverse(path.begin(), path.end());
    std::cout << "Shortest Path between " << from.airportName_ << " and " << to.airportName_ << " is: " << std::endl;
    for (unsigned int i = 0; i < path.size(); i++)
    {
        std::cout << path[i].first.airportName_;
        if (i != path.size() - 1)
            std::cout << " -> ";
    }
    std::cout << std::endl;
    std::cout << "The total distance is: " << path[path.size() - 1].second << std::endl;
    std::cout << std::endl;
    std::cout << "The routes are: " << std::endl;
    for (size_t i = 0; i < path.size(); i++)
    {
        for (size_t j = i + 1; j < path.size(); j++)
        {
            for (auto &e : graph.getEdge(path[i].first, path[j].first))
            {
                e.printEdge();
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    }
}

/**
 * @brief runs iddfs on our graph, returns the path that you can take from the src to dest given the number of layovers
 *
 * @param graph
 * @param from
 * @param to
 * @param max_depth, this represents the max number of layovers/airports that exist between the src and dest
 */
void RunIDDFS(Graph graph, Airport from, Airport to, unsigned int max_depth)
{
    std::map<Airport, Airport> previous;
    std::vector<Airport> path = IDDFS(graph, from, to, max_depth, previous);
    if (path.empty())
    {
        std::cout << "No path found between " << from.airportName_ << " and " << to.airportName_ << " with atmost " << max_depth << " flights" << std::endl;
    }
    else
    {
        std::reverse(path.begin(), path.end());
        // calculate total distance
        int totalDistance = 0;
        for (unsigned int i = 0; i < path.size() - 1; i++)
        {
            totalDistance += graph.getWeight(path[i], path[i + 1]);
        }
        std::cout << "Path between " << from.airportName_ << " and " << to.airportName_ << " with atmost " << max_depth << " flights is: " << std::endl;
        for (unsigned int i = 0; i < path.size(); i++)
        {
            std::cout << path[i].airportName_;
            if (i != path.size() - 1)
                std::cout << " -> ";
        }
        std::cout << std::endl;
        std::cout << "The total distance is: " << totalDistance << std::endl;
    }
}

/**
 * @brief utility function to make string all lowercase
 * 
 * @param str 
 * @return std::string 
 */
std::string toLowercase(std::string str)
{   
    std::string s;
    for (auto& c : str) {
        s += tolower(c);
    }
    return s;
}

/**
 * @brief Get the Airline object By airline id
 * 
 * @param airlines 
 * @param id 
 * @return Airline 
 */
Airline getAirlineByID(std::vector<Airline> airlines, std::string id)
{
    for (const auto &airline : airlines)
    {
        if (airline.airlineID_ == id)
        {
            return airline;
        }
    }
    return Airline();
}

/**
 * @brief Get the Airline object By airline name
 * 
 * @param airlines 
 * @param name
 * @return Airline 
 */
Airline getIDfromAirlineName(std::vector<Airline> airlines, std::string name)
{
    for (const auto &airline : airlines)
    {
        if (toLowercase(airline.name_) == toLowercase(name))
        {
            return airline;
        }
    }
    return Airline();
}

/**
 * @brief this function serves to check if a path exists given additonal conditions/constraints
 *        furthermore, this allows us to answer our leading question if a path exists between the src and
 *        dest by a certain airline or airplane. This function works by running dijkstra on the passed in graph.
 *        We then call a helper function that returns a vector of routes corresponding to the path
 * @param graph
 * @param from
 * @param to
 * @param conditions a struct that holds the airline and airplane type
 */
struct Constraints
{
    std::string airlineID;
    std::string airplaneType;
};

void extraParameters(Graph graph, std::vector<Airline> airlines, Airport from, Airport to, Constraints conditions)
{
    std::vector<std::pair<Airport, double>> path = Dijkstra(graph, from, to);
    std::reverse(path.begin(), path.end());
    std::string airlineName = getAirlineByID(airlines, conditions.airlineID).name_;
    for (size_t i = 0; i < path.size(); i++)
    {
        for (size_t j = i + 1; j < path.size(); j++)
        {
            for (auto &e : graph.getEdge(path[i].first, path[j].first))
            {
                if (e.airlineID_ == conditions.airlineID && (e.planeTypes_.find(conditions.airplaneType) != std::string::npos))
                {
                    std::cout << "A flight was found from " << path[i].first.airportName_ << " to " << path[j].first.airportName_ << " on a " << conditions.airplaneType << " with " << airlineName << std::endl;
                    std::cout << "Here's the details: " << std::endl;
                    e.printEdge();
                }
                else if (e.airlineID_ != conditions.airlineID && (e.planeTypes_.find(conditions.airplaneType) != std::string::npos))
                {
                    std::cout << "A flight was found from " << path[i].first.airportName_ << " to " << path[j].first.airportName_ << " on a " << conditions.airplaneType << " but not with " << airlineName << std::endl;
                    std::cout << "We found a flight with " << e.airline_ << std::endl;
                    std::cout << "Here's the details " << std::endl;
                    e.printEdge();
                }
                else if (e.airlineID_ == conditions.airlineID && (e.planeTypes_.find(conditions.airplaneType) == std::string::npos))
                {
                    std::cout << "A flight was found from " << path[i].first.airportName_ << " to " << path[j].first.airportName_ << " with " << airlineName << " but not on a " << conditions.airplaneType << std::endl;
                    std::cout << "We found a flight on " << e.planeTypes_ << std::endl;
                    std::cout << "Here's the details " << std::endl;
                    e.printEdge();
                }
            }
            std::cout << std::endl;
        }
    }
}

/**
 * 
 * Entry Point here
 * 
 */
int main()
{
    std::vector<Airport> airports = parseAirports("../tests/data/airports.dat");
    std::vector<Airline> airlines = parseAirlines("../tests/data/airlines.dat");
    std::vector<Edge> routes = parseRoutes("../tests/data/routes.dat");

    Graph graph(airports, airlines, routes);
    Constraints c;

    // Parameters to change here // 
    Airport from = graph.getAirportByIATA("CMI"); // change this to a different airport iata
    Airport to = graph.getAirportByIATA("LHR"); // change this to a different airport iata
    std::string airline = "american airlines"; // change this to a different airline
    c.airplaneType = "747"; // change this to a different airplane type

    std::string airlineID = getIDfromAirlineName(airlines, airline).airlineID_;
    c.airlineID = airlineID;

    extraParameters(graph, airlines, from, to, c);
    
    // running algorithms alone here // 
    // RunDijkstra(graph, from, to);
    // RunIDDFS(graph, from, to, 2);
}