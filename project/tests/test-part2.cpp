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
TEST_CASE("Construction 0 (No edges)", "[weight=1]") {
  // no routes exists between airports (empty edges vector)
  std::vector<Edge> routes;

  // init graph
  Graph graph(airports, airlines, routes);
  graph.buildGraph();
  // graph.printGraph();

  // count connected components
  REQUIRE(graph.countConnectedComponents() == 5);

  // adjacency list for i-th airport should be empty 
  for (const auto& airport : airports) {
    REQUIRE(graph.getAdjacentAirports(airport).size() == 0);
  }
}

// one edge (ap1 to ap2) case
TEST_CASE("Construction 1 (1 edge: ap1 to ap2)", "[weight=1]") {
  // no routes exists between airports (empty edges vector)
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

// one edge (ap1 to ap2) case
TEST_CASE("Construction 2 (4 edges: ap1 to ap2, edge ap1 to ap3, edge ap1 to ap4, edge ap1 to ap5)", "[weight=1]") {
  // ap2 to ap3
  Edge e3("a1", "id", "IATA2", "id2", "IATA3", "id3", true, 1, "t1");
  Edge e4("a2", "id", "IATA3", "id3", "IATA2", "id2", true, 2, "t2");
  
  // ap1 to ap4
  Edge e5("a1", "id", "IATA1", "id1", "IATA4", "id4", true, 1, "t1");
  Edge e6("a2", "id", "IATA4", "id4", "IATA1", "id1", true, 2, "t2");
  
  // ap1 to ap5
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
  for (const auto& airport : graph.getAdjacentAirports(ap1)) {
    if (airport == ap4) {
      hasAP4 = true;
    }
    if (airport == ap5) {
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