#include "dijkstra.h"
#include "IDDFS.h"
#include "graph.h"
#include "parser.h"
#include "airport.h"

#include <limits>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

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
  std::cout << "Shortest Path between " << from.getAirportName() << " and " << to.getAirportName() << " is: " << std::endl;
  for (unsigned int i = 0; i < path.size(); i++)
  {
    std::cout << path[i].first.getAirportName();
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
    std::cout << "No path found between " << from.getAirportName() << " and " << to.getAirportName() << " with atmost " << max_depth << " flights" << std::endl;
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
    std::cout << "Path between " << from.getAirportName() << " and " << to.getAirportName() << " with atmost " << max_depth << " flights is: " << std::endl;
    for (unsigned int i = 0; i < path.size(); i++)
    {
      std::cout << path[i].getAirportName();
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
  for (auto &c : str)
  {
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
    if (airline.getAirlineID() == id)
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
    if (toLowercase(airline.getName()) == toLowercase(name))
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
  std::string airlineName = getAirlineByID(airlines, conditions.airlineID).getName();
  for (size_t i = 0; i < path.size(); i++)
  {
    for (size_t j = i + 1; j < path.size(); j++)
    {
      for (auto &e : graph.getEdge(path[i].first, path[j].first))
      {
        if (e.getAirlineID() == conditions.airlineID && (e.getPlaneTypes().find(conditions.airplaneType) != std::string::npos))
        {
          std::cout << "A flight was found from " << path[i].first.getAirportName() << " to " << path[j].first.getAirportName() << " on a " << conditions.airplaneType << " with " << airlineName << std::endl;
          std::cout << "Here's the details: " << std::endl;
          e.printEdge();
        }
        else if (e.getAirlineID() != conditions.airlineID && (e.getPlaneTypes().find(conditions.airplaneType) != std::string::npos))
        {
          std::cout << "A flight was found from " << path[i].first.getAirportName() << " to " << path[j].first.getAirportName() << " on a " << conditions.airplaneType << " but not with " << airlineName << std::endl;
          std::cout << "We found a flight with " << e.getAirline() << std::endl;
          std::cout << "Here's the details " << std::endl;
          e.printEdge();
        }
        else if (e.getAirlineID() == conditions.airlineID && (e.getPlaneTypes().find(conditions.airplaneType) == std::string::npos))
        {
          std::cout << "A flight was found from " << path[i].first.getAirportName() << " to " << path[j].first.getAirportName() << " with " << airlineName << " but not on a " << conditions.airplaneType << std::endl;
          std::cout << "We found a flight on " << e.getPlaneTypes() << std::endl;
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
int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    std::cout << "No Extra Command Line Argument Passed, Refer to our Read.me to see what's available" << std::endl;
    std::cout << "Available commands: " << std::endl;
    std::cout << "./main default " << std::endl;
    std::cout << "./main parser [airport file] [airline file] [routes file]" << std::endl;
    std::cout << std::endl;

    std::cout << "If you want to use an already parsed dataset" << std::endl;
    std::cout << "./main dijkstra0 [src airport IATA] [dest airport IATA]" << std::endl;
    std::cout << "./main iddfs0 [src airport IATA] [dest airport IATA] [number of layovers]" << std::endl;
    std::cout << "./main extra0 [src airport IATA] [dest airport IATA] [airline] [airplane]" << std::endl;
    std::cout << "./main dfs0 [starting airport IATA]" << std::endl;
    std::cout << std::endl;

    std::cout << "If you want pass in your own dataset" << std::endl;
    std::cout << "./main dijkstra1 [airport file] [airline file] [routes file] [src airport IATA] [dest airport IATA]" << std::endl;
    std::cout << "./main iddfs1 [airport file] [airline file] [routes file] [src airport IATA] [dest airport IATA] [number of layovers]" << std::endl;
    std::cout << "./main extra1 [airport file] [airline file] [routes file] [src airport IATA] [dest airport IATA] [airline] [airplane]" << std::endl;
    std::cout << "./main dfs1 [airport file] [airline file] [routes file] [starting airport]" << std::endl;
    std::cout << std::endl;
    
    std::cout << "If you're feeling risky" << std::endl;
    std::cout << "./main dontrunthis" << std::endl;
  }
  else if (argc >= 2)
  {
    if (strcmp(argv[1], "default") == 0)
    {
      std::cout << "This may take 30-60 seconds" << std::endl;
      Constraints c;
      std::vector<Airport> airports = parseAirports("../tests/data/airports.dat");
      std::vector<Airline> airlines = parseAirlines("../tests/data/airlines.dat");
      std::vector<Edge> routes = parseRoutes("../tests/data/routes.dat");
      Graph graph(airports, airlines, routes);

      Airport from = graph.getAirportByIATA("CMI"); // change this to a different airport iata
      Airport to = graph.getAirportByIATA("LHR");   // change this to a different airport iata
      std::string airline = "american airlines";    // change this to a different airline
      c.airplaneType = "747";                       // change this to a different airplane type

      std::string airlineID = getIDfromAirlineName(airlines, airline).getAirlineID();
      c.airlineID = airlineID;
      extraParameters(graph, airlines, from, to, c);
    }
    else if (strcmp(argv[1], "parser") == 0)
    {
      std::cout << "This may take 30-60 seconds" << std::endl;
      std::cout << "This just parses it. We're not gonna this all of this data out" << std::endl;
      std::vector<Airport> airports = parseAirports(argv[2]);
      std::vector<Airline> airlines = parseAirlines(argv[3]);
      std::vector<Edge> routes = parseRoutes(argv[4]);
    }
    else if (strcmp(argv[1], "dijkstra0") == 0)
    {
      std::cout << "This may take 30-60 seconds" << std::endl;
      std::vector<Airport> airports = parseAirports("../tests/data/airports.dat");
      std::vector<Airline> airlines = parseAirlines("../tests/data/airlines.dat");
      std::vector<Edge> routes = parseRoutes("../tests/data/routes.dat");
      Graph graph(airports, airlines, routes);

      Airport from = graph.getAirportByIATA(argv[2]);
      Airport to = graph.getAirportByIATA(argv[3]);
      RunDijkstra(graph, from, to);
    }
    else if (strcmp(argv[1], "iddfs0") == 0)
    {
      std::cout << "This may take 30-60 seconds" << std::endl;
      std::vector<Airport> airports = parseAirports("../tests/data/airports.dat");
      std::vector<Airline> airlines = parseAirlines("../tests/data/airlines.dat");
      std::vector<Edge> routes = parseRoutes("../tests/data/routes.dat");
      Graph graph(airports, airlines, routes);

      Airport from = graph.getAirportByIATA(argv[2]);
      Airport to = graph.getAirportByIATA(argv[3]);
      int numberLayover = std::stoi(argv[4]);
      RunIDDFS(graph, from, to, numberLayover);
    }
    else if (strcmp(argv[1], "extra0") == 0)
    {
      std::cout << "If the airline contains a space, please wrap the airline name in double quotes" << std::endl;
      std::cout << "This may take 30-60 seconds" << std::endl;
      std::vector<Airport> airports = parseAirports("../tests/data/airports.dat");
      std::vector<Airline> airlines = parseAirlines("../tests/data/airlines.dat");
      std::vector<Edge> routes = parseRoutes("../tests/data/routes.dat");
      Graph graph(airports, airlines, routes);

      Airport from = graph.getAirportByIATA(argv[2]);
      Airport to = graph.getAirportByIATA(argv[3]);
      Constraints c;
      c.airplaneType = argv[5];
      std::string airlineID = getIDfromAirlineName(airlines, argv[4]).getAirlineID();
      c.airlineID = airlineID;

      extraParameters(graph, airlines, from, to, c);
    }
    else if (strcmp(argv[1], "dfs0") == 0)
    {
      std::cout << "This may take 30-60 seconds" << std::endl;
      std::vector<Airport> airports = parseAirports("../tests/data/airports.dat");
      std::vector<Airline> airlines = parseAirlines("../tests/data/airlines.dat");
      std::vector<Edge> routes = parseRoutes("../tests/data/routes.dat");
      Graph graph(airports, airlines, routes);

      graph.setStartingAirport(graph.getAirportByIATA(argv[2]));
      graph.dfs(graph.getStartingAirport());
      for (const auto &e : graph.getDFSpath())
      {
        std::cout << e.getAirportName() << std::endl;
      }
      graph.clearTraversal();
    }
    else if (strcmp(argv[1], "dijkstra1") == 0)
    {
      std::cout << "This may take 30-60 seconds" << std::endl;
      std::vector<Airport> airports = parseAirports(argv[2]);
      std::vector<Airline> airlines = parseAirlines(argv[3]);
      std::vector<Edge> routes = parseRoutes(argv[4]);
      Graph graph(airports, airlines, routes);

      Airport from = graph.getAirportByIATA(argv[5]);
      Airport to = graph.getAirportByIATA(argv[6]);
      RunDijkstra(graph, from, to);
    }
    else if (strcmp(argv[1], "iddfs1") == 0)
    {
      std::cout << "This may take 30-60 seconds" << std::endl;
      std::vector<Airport> airports = parseAirports(argv[2]);
      std::vector<Airline> airlines = parseAirlines(argv[3]);
      std::vector<Edge> routes = parseRoutes(argv[4]);
      Graph graph(airports, airlines, routes);

      Airport from = graph.getAirportByIATA(argv[5]);
      Airport to = graph.getAirportByIATA(argv[6]);
      int numberLayover = std::stoi(argv[7]);
      RunIDDFS(graph, from, to, numberLayover);
    }
    else if (strcmp(argv[1], "extra1") == 0)
    {
      std::cout << "This may take 30-60 seconds" << std::endl;
      std::vector<Airport> airports = parseAirports(argv[2]);
      std::vector<Airline> airlines = parseAirlines(argv[3]);
      std::vector<Edge> routes = parseRoutes(argv[4]);
      Graph graph(airports, airlines, routes);

      Airport from = graph.getAirportByIATA(argv[5]);
      Airport to = graph.getAirportByIATA(argv[6]);
      Constraints c;
      c.airplaneType = argv[8];
      std::string airlineID = getIDfromAirlineName(airlines, argv[7]).getAirlineID();
      c.airlineID = airlineID;

      extraParameters(graph, airlines, from, to, c);
    }
    else if (strcmp(argv[1], "dfs1") == 0)
    {
      std::cout << "This may take 30-60 seconds" << std::endl;
      std::vector<Airport> airports = parseAirports(argv[2]);
      std::vector<Airline> airlines = parseAirlines(argv[3]);
      std::vector<Edge> routes = parseRoutes(argv[4]);
      Graph graph(airports, airlines, routes);

      graph.setStartingAirport(graph.getAirportByIATA(argv[5]));
      graph.dfs(graph.getStartingAirport());
      for (const auto &e : graph.getDFSpath())
      {
        std::cout << e.getAirportName() << std::endl;
      }
      graph.clearTraversal();
    }
    else if (strcmp(argv[1], "dontrunthis") == 0)
    {
      std::cout << "https://www.youtube.com/watch?v=dQw4w9WgXcQ" << std::endl;
    }
    else
    {
      std::cout << "http://www.script-o-rama.com/movie_scripts/s/shrek-2-script-transcript.html" << std::endl;
      std::cout << "Happy Holidays!" << std::endl;
    }
  }
  else
  {
    std::cout << "http://www.script-o-rama.com/movie_scripts/s/shrek-2-script-transcript.html" << std::endl;
    std::cout << "Happy Holidays!" << std::endl;
  }
}
