#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <iostream>
#include <algorithm>

#include "graph.h"
#include "airport.h"
#include "airline.h"
#include "edge.h"

// hard-coded airports
Airport ap01("id1", "a1", "c1", "c1", "IATA1", "ICAO1", 1, 1, 1, "tz1", "dst1", "tz1", "t1");
Airport ap02("id2", "a2", "c2", "c2", "IATA2", "ICAO2", 2, 2, 2, "tz2", "dst2", "tz2", "t2");
Airport ap03("id3", "a3", "c3", "c3", "IATA3", "ICAO3", 3, 3, 3, "tz3", "dst3", "tz3", "t3");
Airport ap04("id4", "a4", "c4", "c4", "IATA4", "ICAO4", 4, 4, 4, "tz4", "dst4", "tz4", "t4");
Airport ap05("id5", "a5", "c5", "c5", "IATA5", "ICAO5", 5, 5, 5, "tz5", "dst5", "tz5", "t5");
std::vector<Airport> airports0 = {ap01, ap02, ap03, ap04, ap05};

// hard-coded airlines
Airline al01("id1", "n1", "a1", "IATA-A1", "ICAO-A1", "c1", "c1", true);
Airline al02("id2", "n2", "a2", "IATA-A2", "ICAO-A2", "c2", "c2", true);
Airline al03("id3", "n3", "a3", "IATA-A3", "ICAO-A3", "c3", "c3", true);
Airline al04("id4", "n4", "a4", "IATA-A4", "ICAO-A4", "c4", "c4", true);
Airline al05("id5", "n5", "a5", "IATA-A5", "ICAO-A5", "c5", "c5", true);
std::vector<Airline> airlines0 = {al01, al02, al03, al04, al05};

// DFS test cases
TEST_CASE("Construction 0 DFS", "[weight=1][part=4]")
{
  // no routes exists between airports (empty edges vector)
  std::vector<Edge> routes;

  // init graph
  Graph graph(airports0, airlines0, routes);

  // dfs path is empty for every starting airport because its just airports in space
  for (const auto &ap : airports0)
  {
    graph.setStartingAirport(ap);
    graph.dfs(graph.getStartingAirport());
    REQUIRE(graph.getDFSpath().size() == 0);
  }

  // all airports are on different components, "inComponents" runs dfs
  for (size_t i = 0; i < airports0.size(); i++)
  {
    for (size_t j = i + 1; j < airports0.size(); j++)
    {
      REQUIRE(graph.inComponent(airports0[i], airports0[j]) == false);
    }
  }
  graph.clearTraversal();
}

TEST_CASE("Construction 1 DFS", "[weight=1][part=4]")
{
  // ap1 to ap2 and back
  Edge e1("a1", "id", "IATA1", "id1", "IATA2", "id2", true, 1, "t1");
  Edge e2("a2", "id", "IATA2", "id2", "IATA1", "id1", true, 2, "t2");
  std::vector<Edge> routes = {e1, e2};

  // init graph
  Graph graph(airports0, airlines0, routes);

  // expected dfs path vector for airports 1
  std::vector<Airport> expectPathAP1 = {ap02};
  graph.setStartingAirport(ap01);
  graph.dfs(graph.getStartingAirport());
  REQUIRE(graph.getDFSpath().size() == 1);
  REQUIRE(graph.getDFSpath() == expectPathAP1);
  graph.clearTraversal();

  // expected dfs path vector for airports 2
  std::vector<Airport> expectPathAP2 = {ap01};
  graph.setStartingAirport(ap02);
  graph.dfs(graph.getStartingAirport());
  REQUIRE(graph.getDFSpath().size() == 1);
  REQUIRE(graph.getDFSpath() == expectPathAP2);
  graph.clearTraversal();

  std::vector<Airport> inSpace = {ap03, ap04, ap05};
  // dfs path is empty for every starting airport because its just airports in space
  for (const auto &ap : inSpace)
  {
    graph.setStartingAirport(ap);
    graph.dfs(graph.getStartingAirport());
    REQUIRE(graph.getDFSpath().size() == 0);
  }

  // all airports are on different components, "inComponents" runs dfs
  for (size_t i = 0; i < inSpace.size(); i++)
  {
    for (size_t j = i + 1; j < inSpace.size(); j++)
    {
      REQUIRE(graph.inComponent(inSpace[i], inSpace[j]) == false);
    }
  }
  graph.clearTraversal();
}

TEST_CASE("Construction 3 DFS", "[weight=1][part=4]")
{
  Airport ap1("id1", "a1", "c1", "c1", "IATA1", "ICAO1", 1, 1, 1, "tz1", "dst1", "tz1", "t1");
  Airport ap2("id2", "a2", "c2", "c2", "IATA2", "ICAO2", 2, 2, 2, "tz2", "dst2", "tz2", "t2");
  Airport ap3("id3", "a3", "c3", "c3", "IATA3", "ICAO3", 3, 3, 3, "tz3", "dst3", "tz3", "t3");
  Airport ap4("id4", "a4", "c4", "c4", "IATA4", "ICAO4", 4, 4, 4, "tz4", "dst4", "tz4", "t4");
  Airport ap5("id5", "a5", "c5", "c5", "IATA5", "ICAO5", 5, 5, 5, "tz5", "dst5", "tz5", "t5");
  Airport ap6("id5", "a6", "c6", "c6", "IATA6", "ICAO6", 6, 6, 6, "tz6", "dst6", "tz6", "t6");
  Airport ap7("id5", "a7", "c7", "c7", "IATA7", "ICAO7", 7, 7, 7, "tz7", "dst7", "tz7", "t7");
  Airport ap8("id5", "a8", "c8", "c8", "IATA8", "ICAO8", 8, 8, 8, "tz8", "dst8", "tz8", "t8");
  Airport ap9("id5", "a9", "c9", "c9", "IATA9", "ICAO9", 9, 9, 9, "tz9", "dst9", "tz9", "t9");
  Airport ap10("id5", "a10", "c10", "c10", "IATA10", "ICAO10", 10, 10, 10, "tz10", "dst10", "tz10", "t10");
  Airport ap11("id5", "a11", "c11", "c11", "IATA11", "ICAO11", 11, 11, 11, "tz11", "dst11", "tz11", "t11");
  Airport ap12("id5", "a12", "c12", "c12", "IATA12", "ICAO12", 12, 12, 12, "tz12", "dst12", "tz12", "t12");
  std::vector<Airport> airports = {ap1, ap2, ap3, ap4, ap5, ap6, ap7, ap8, ap9, ap10, ap11, ap12};

  Edge e12("al", "id", "IATA1", "id1", "IATA2", "id2", true, 1, "t");
  Edge e13("al", "id", "IATA1", "id1", "IATA3", "id3", true, 1, "t");
  Edge e24("al", "id", "IATA2", "id2", "IATA4", "id4", true, 1, "t");
  Edge e34("al", "id", "IATA3", "id3", "IATA4", "id4", true, 1, "t");
  Edge e49("al", "id", "IATA4", "id4", "IATA9", "id9", true, 1, "t");
  Edge e16("al", "id", "IATA1", "id1", "IATA6", "id6", true, 1, "t");
  Edge e68("al", "id", "IATA6", "id6", "IATA8", "id8", true, 1, "t");
  Edge e67("al", "id", "IATA6", "id6", "IATA7", "id7", true, 1, "t");
  Edge e510("al", "id", "IATA5", "id5", "IATA10", "id10", true, 1, "t");
  std::vector<Edge> routes = {e12, e13, e24, e34, e49, e16, e68, e67, e510};

  // init graph
  Graph graph(airports, airlines0, routes);
  graph.setStartingAirport(ap1);
  graph.dfs(graph.getStartingAirport());

  std::vector<Airport> expectedTraversal = {ap2, ap4, ap9, ap3, ap6, ap8, ap7};
  REQUIRE(graph.getDFSpath() == expectedTraversal);
  graph.clearTraversal();

  // checks: ap1 is in a different component
  graph.setStartingAirport(ap1);
  std::vector<Airport> nonConnectedAPs = {ap5, ap10, ap11, ap12};
  for (const auto& nonConnectedAP : nonConnectedAPs) {
    REQUIRE(graph.inComponent(graph.getStartingAirport(), nonConnectedAP) == false);
  }
  graph.clearTraversal();
}