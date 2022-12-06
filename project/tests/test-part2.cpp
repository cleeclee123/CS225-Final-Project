#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <iostream>
#include <algorithm>

#include "graph.h"
#include "airport.h"
#include "airline.h"
#include "edge.h"

// hard-coded airports
Airport ap1("id1", "a1", "c1", "c1", "IATA1", "ICAO1", 1, 1, 1, "tz1", "dst1", "tz1", "t1");
Airport ap2("id2", "a2", "c2", "c2", "IATA2", "ICAO2", 2, 2, 2, "tz2", "dst2", "tz2", "t2");
Airport ap3("id3", "a3", "c3", "c3", "IATA3", "ICAO3", 3, 3, 3, "tz3", "dst3", "tz3", "t3");
Airport ap4("id4", "a4", "c4", "c4", "IATA4", "ICAO4", 4, 4, 4, "tz4", "dst4", "tz4", "t4");
Airport ap5("id5", "a5", "c5", "c5", "IATA5", "ICAO5", 5, 5, 5, "tz5", "dst5", "tz5", "t5");
std::vector<Airport> airports = {ap1, ap2, ap3, ap4, ap5};

// hard-coded airlines
Airline al1("id1", "n1", "a1", "IATA-A1", "ICAO-A1", "c1", "c1", true);
Airline al2("id2", "n2", "a2", "IATA-A2", "ICAO-A2", "c2", "c2", true);
Airline al3("id3", "n3", "a3", "IATA-A3", "ICAO-A3", "c3", "c3", true);
Airline al4("id4", "n4", "a4", "IATA-A4", "ICAO-A4", "c4", "c4", true);
Airline al5("id5", "n5", "a5", "IATA-A5", "ICAO-A5", "c5", "c5", true);
std::vector<Airline> airlines = {al1, al2, al3, al4, al5};

// no edge/route case
TEST_CASE("Construction 0 (No edges)", "[weight=1][part=2]")
{
  // no routes exists between airports (empty edges vector)
  std::vector<Edge> routes;

  // init graph
  Graph graph(airports, airlines, routes);
  graph.buildGraph();
  // graph.printGraph();

  // count connected components
  REQUIRE(graph.countConnectedComponents() == 5);

  // adjacency list for i-th airport should be empty
  for (const auto &airport : airports)
  {
    REQUIRE(graph.getAdjacentAirports(airport).size() == 0);
  }
}

// one edge (ap1 to ap2) case, undirected
TEST_CASE("Construction 1 (1 edge: ap1 to ap2)", "[weight=1][part=2]")
{
  // ap1 to ap2 and back
  Edge e1("a1", "id", "IATA1", "id1", "IATA2", "id2", true, 1, "t1");
  Edge e2("a2", "id", "IATA2", "id2", "IATA1", "id1", true, 2, "t2");
  std::vector<Edge> routes = {e1, e2};

  // init graph
  Graph graph(airports, airlines, routes);
  graph.buildGraph();
  // graph.printGraph();

  // count connected components
  REQUIRE(graph.countConnectedComponents() == 4);

  // adjacency list for airport 1 should be size 1 and contain airport 2
  REQUIRE(graph.getAdjacentAirports(ap1).size() == 1);
  REQUIRE(graph.getAdjacentAirports(ap1)[0] == ap2);

  // adjacency list for airport 2 should be size 1 and contain airport 1
  REQUIRE(graph.getAdjacentAirports(ap2).size() == 1);
  REQUIRE(graph.getAdjacentAirports(ap2)[0] == ap1);
}

// 4 edges: ap1 to ap2, edge ap1 to ap3, edge ap1 to ap4, edge ap1 to ap5, undirected
TEST_CASE("Construction 2 (4 edges: ap1 to ap2, edge ap1 to ap3, edge ap1 to ap4, edge ap1 to ap5)", "[weight=1][part=2]")
{
  // ap2 to ap3 and back 
  Edge e3("a1", "id", "IATA2", "id2", "IATA3", "id3", true, 1, "t1");
  Edge e4("a2", "id", "IATA3", "id3", "IATA2", "id2", true, 2, "t2");

  // ap1 to ap4 and back
  Edge e5("a1", "id", "IATA1", "id1", "IATA4", "id4", true, 1, "t1");
  Edge e6("a2", "id", "IATA4", "id4", "IATA1", "id1", true, 2, "t2");

  // ap1 to ap5 and back
  Edge e7("a1", "id", "IATA1", "id1", "IATA5", "id5", true, 1, "t1");
  Edge e8("a2", "id", "IATA5", "id5", "IATA1", "id1", true, 2, "t2");

  std::vector<Edge> routes = {e3, e4, e5, e6, e7, e8};

  // init graph
  Graph graph(airports, airlines, routes);
  graph.buildGraph();
  // graph.printGraph();

  // count connected components
  REQUIRE(graph.countConnectedComponents() == 2);

  // adjacency list for airport 1 should be size 2 and contain airport 4 and airport 5
  REQUIRE(graph.getAdjacentAirports(ap1).size() == 2);
  bool hasAP4 = false;
  bool hasAP5 = false;
  for (const auto &airport : graph.getAdjacentAirports(ap1))
  {
    if (airport == ap4)
    {
      hasAP4 = true;
    }
    if (airport == ap5)
    {
      hasAP5 = true;
    }
  }
  REQUIRE(hasAP4);
  REQUIRE(hasAP5);

  // adjacency list for airport 4 should be size 1 and contain airport 1
  REQUIRE(graph.getAdjacentAirports(ap4).size() == 1);
  REQUIRE(graph.getAdjacentAirports(ap4)[0] == ap1);

  // adjacency list for airport 5 should be size 1 and contain airport 1
  REQUIRE(graph.getAdjacentAirports(ap5).size() == 1);
  REQUIRE(graph.getAdjacentAirports(ap5)[0] == ap1);

  // adjacency list for airport 2 should be size 1 and contain airport 3
  REQUIRE(graph.getAdjacentAirports(ap2).size() == 1);
  REQUIRE(graph.getAdjacentAirports(ap2)[0] == ap3);

  // adjacency list for airport 3 should be size 1 and contain airport 2
  REQUIRE(graph.getAdjacentAirports(ap3).size() == 1);
  REQUIRE(graph.getAdjacentAirports(ap3)[0] == ap2);
}

// bigger test case, directed
TEST_CASE("Construction 3 (see jpg)", "[weight=1][part=2]")
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
  Graph graph(airports, airlines, routes);
  graph.buildGraph();
  graph.printGraph();

  // count connected components
  // REQUIRE(graph.countConnectedComponents() == 4);
  
  // adjacency list for airport 7 should be size 0
  REQUIRE(graph.getAdjacentAirports(ap7).size() == 0);
  
  // adjacency list for airport 8 should be size 0
  REQUIRE(graph.getAdjacentAirports(ap8).size() == 0);
  
  // adjacency list for airport 9 should be size 0
  REQUIRE(graph.getAdjacentAirports(ap9).size() == 0);

  // adjacency list for airport 10 should be size 0
  REQUIRE(graph.getAdjacentAirports(ap10).size() == 0);

  // adjacency list for airport 11 should be size 0
  REQUIRE(graph.getAdjacentAirports(ap11).size() == 0);

  // adjacency list for airport 12 should be size 0
  REQUIRE(graph.getAdjacentAirports(ap12).size() == 0);

  // adjacency list for airport 5 should be size 1, contains airport 10
  REQUIRE(graph.getAdjacentAirports(ap5).size() == 1);
  REQUIRE(graph.getAdjacentAirports(ap5)[0] == ap10);

  // adjacency list for airport 1 should be size 3, contains airports 2,3,6
  REQUIRE(graph.getAdjacentAirports(ap1).size() == 3);
  bool has2, has3, has6;
  for (const auto& ap : graph.getAdjacentAirports(ap1)) {
    if (ap == ap2) has2 = true;
    if (ap == ap3) has3 = true;
    if (ap == ap6) has6 = true;
  }
  REQUIRE(has2);
  REQUIRE(has3);
  REQUIRE(has6);

  // adjacency list for airport 2 should be size 1, contains airport 4
  REQUIRE(graph.getAdjacentAirports(ap2).size() == 1);
  REQUIRE(graph.getAdjacentAirports(ap2)[0] == ap4);
  
  // adjacency list for airport 3 should be size 1, contains airport 4
  REQUIRE(graph.getAdjacentAirports(ap3).size() == 1);
  REQUIRE(graph.getAdjacentAirports(ap3)[0] == ap4);

  // adjacency list for airport 4 should be size 1, contains airport 9
  REQUIRE(graph.getAdjacentAirports(ap4).size() == 1);
  REQUIRE(graph.getAdjacentAirports(ap4)[0] == ap9);

  // adjacency list for airport 6 should be size 2, contains airport 7, airport 8
  REQUIRE(graph.getAdjacentAirports(ap6).size() == 2);
  std::vector<Airport> adjAP6 = graph.getAdjacentAirports(ap6);
  bool has7, has8;
  for (const auto& ap : graph.getAdjacentAirports(ap6)) {
    if (ap == ap7) has7 = true;
    if (ap == ap8) has8 = true;
  }
  REQUIRE(has7);
  REQUIRE(has8);
}