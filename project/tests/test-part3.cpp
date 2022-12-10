#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <iostream>
#include <algorithm>

#include "graph.h"
#include "airport.h"
#include "airline.h"
#include "edge.h"
#include "dijkstra.h"
#include "iddfs.h"

// hard-coded airlines
Airline airline1("id1", "n1", "a1", "IATA-A1", "ICAO-A1", "c1", "c1", true);
Airline airline2("id2", "n2", "a2", "IATA-A2", "ICAO-A2", "c2", "c2", true);
Airline airline3("id3", "n3", "a3", "IATA-A3", "ICAO-A3", "c3", "c3", true);
Airline airline4("id4", "n4", "a4", "IATA-A4", "ICAO-A4", "c4", "c4", true);
Airline airline5("id5", "n5", "a5", "IATA-A5", "ICAO-A5", "c5", "c5", true);
std::vector<Airline> airlineList = {airline1, airline2, airline3, airline4, airline5};

Airport airport1("id1", "a1", "c1", "c1", "IATA1", "ICAO1", 1, 1, 1, "tz1", "dst1", "tz1", "t1");
Airport airport2("id2", "a2", "c2", "c2", "IATA2", "ICAO2", 2, 2, 2, "tz2", "dst2", "tz2", "t2");
Airport airport3("id3", "a3", "c3", "c3", "IATA3", "ICAO3", 3, 3, 3, "tz3", "dst3", "tz3", "t3");
Airport airport4("id4", "a4", "c4", "c4", "IATA4", "ICAO4", 4, 4, 4, "tz4", "dst4", "tz4", "t4");
Airport airport5("id5", "a5", "c5", "c5", "IATA5", "ICAO5", 5, 5, 5, "tz5", "dst5", "tz5", "t5");
Airport airport6("id6", "a6", "c6", "c6", "IATA6", "ICAO6", 6, 6, 6, "tz6", "dst6", "tz6", "t6");
Airport airport7("id7", "a7", "c7", "c7", "IATA7", "ICAO7", 7, 7, 7, "tz7", "dst7", "tz7", "t7");
Airport airport8("id8", "a8", "c8", "c8", "IATA8", "ICAO8", 8, 8, 8, "tz8", "dst8", "tz8", "t8");
Airport airport9("id9", "a9", "c9", "c9", "IATA9", "ICAO9", 9, 9, 9, "tz9", "dst9", "tz9", "t9");
Airport airport10("id10", "a10", "c10", "c10", "IATA10", "ICAO10", 10, 10, 10, "tz10", "dst10", "tz10", "t10");
Airport airport11("id11", "a11", "c11", "c11", "IATA11", "ICAO11", 11, 11, 11, "tz11", "dst11", "tz11", "t11");
Airport airport12("id12", "a12", "c12", "c12", "IATA12", "ICAO12", 12, 12, 12, "tz12", "dst12", "tz12", "t12");
std::vector<Airport> airportList = {airport1, airport2, airport3, airport4, airport5, airport6, airport7, airport8, airport9, airport10, airport11, airport12};

Edge e12("al", "id-edge-12", "IATA1", "id1", "IATA2", "id2", true, 1, "t");
Edge e13("al", "id", "IATA1", "id1", "IATA3", "id3", true, 1, "t");
Edge e24("al", "id", "IATA2", "id2", "IATA4", "id4", true, 1, "t");
Edge e34("al", "id", "IATA3", "id3", "IATA4", "id4", true, 1, "t");
Edge e49("al", "id", "IATA4", "id4", "IATA9", "id9", true, 1, "t");
Edge e16("al", "id", "IATA1", "id1", "IATA6", "id6", true, 1, "t");
Edge e68("al", "id-edge-68", "IATA6", "id6", "IATA8", "id8", true, 1, "t");  
Edge e67("al", "id", "IATA6", "id6", "IATA7", "id7", true, 1, "t");
Edge e510("al", "id", "IATA5", "id5", "IATA10", "id10", true, 1, "t");
std::vector<Edge> routes = {e12, e13, e24, e34, e49, e16, e68, e67, e510};

// init graph
Graph graph(airportList, airlineList, routes);

//Test Dijkstra
TEST_CASE("Shortest path from ap1 to ap9 (Construction 3)", "[weight=1][part=3]") {
    std::vector<std::pair<Airport, double>> expected = {
        {airport1, 0},
        {airport2, airport1.distance(airport2)},
        {airport4, airport1.distance(airport2) + airport2.distance(airport4)},
        {airport9, airport1.distance(airport2) + airport2.distance(airport4) + airport4.distance(airport9)}
    };
    std::vector<std::pair<Airport, double>> actual = Dijkstra(graph, airport1, airport9);
    //reverse actual
    std::reverse(actual.begin(), actual.end());
    REQUIRE(expected == actual);
}

//Test Dijkstra when no path exists (due to unconnected components)
TEST_CASE("Shortest path from ap1 to ap5 (Construction 3)", "[weight=1][part=3]") {
    std::vector<std::pair<Airport, double>> expected;
    std::vector<std::pair<Airport, double>> actual = Dijkstra(graph, airport1, airport5);
    //reverse actual
    std::reverse(actual.begin(), actual.end());
    //print actual
    REQUIRE(expected == actual);
}

//Test Dijkstra when there is only one path
TEST_CASE("Shortest path from ap5 to ap10 (Construction 3)", "[weight=1][part=3]") {
    std::vector<std::pair<Airport, double>> expected = {
        {airport5, 0},
        {airport10, airport5.distance(airport10)}
    };
    std::vector<std::pair<Airport, double>> actual = Dijkstra(graph, airport5, airport10);
    //reverse actual
    std::reverse(actual.begin(), actual.end());
    REQUIRE(expected == actual);
}

//Test IDDFS
TEST_CASE("First path from ap1 to ap9 within 3 flights(Construction 3)", "[weight=1][part=3]") {
    std::vector<Airport> expected = {airport1, airport2, airport4, airport9};
    std::map<Airport, Airport> previous;
    std::vector<Airport> actual = IDDFS(graph, airport1, airport9, 3, previous);
    //reverse actual
    std::reverse(actual.begin(), actual.end());
    REQUIRE(expected == actual);
}

//Test IDDFS when path does not exist within flight limit
TEST_CASE("First path from ap1 to ap9 within 2 flights(Construction 3)", "[weight=1][part=3]") {
    std::vector<Airport> expected;
    std::map<Airport, Airport> previous;
    std::vector<Airport> actual = IDDFS(graph, airport1, airport9, 2, previous);
    //reverse actual
    std::reverse(actual.begin(), actual.end());
    REQUIRE(expected == actual);
}

//Test IDDFS when there is only one path
TEST_CASE("First path from ap5 to ap10 within 2 flights(Construction 3)", "[weight=1][part=3]") {
    std::vector<Airport> expected = {airport5, airport10};
    std::map<Airport, Airport> previous;
    std::vector<Airport> actual = IDDFS(graph, airport5, airport10, 2, previous);
    //reverse actual
    std::reverse(actual.begin(), actual.end());
    REQUIRE(expected == actual);
}

//Test IDDFS when componenents are not connected
TEST_CASE("First path from ap1 to ap5 within 3 flights(Construction 3)", "[weight=1][part=3]") {
    std::vector<Airport> expected;
    std::map<Airport, Airport> previous;
    std::vector<Airport> actual = IDDFS(graph, airport1, airport5, 3, previous);
    //reverse actual
    std::reverse(actual.begin(), actual.end());
    REQUIRE(expected == actual);
}