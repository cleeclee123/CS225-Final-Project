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

void RunDijkstra(Graph graph, Airport from, Airport to) {
    std::vector<std::pair<Airport, double>> path = Dijkstra(graph, from, to);
    std::reverse(path.begin(), path.end());
    std::cout << "Shortest Path between " << from.airportName_ << " and " << to.airportName_ << " is: " << std::endl;
    for (unsigned int i = 0; i < path.size(); i++) {
        std::cout << path[i].first.airportName_;
        if (i != path.size() - 1) std::cout << " -> ";
    }
    std::cout << std::endl;
    std::cout << "The total distance is: " << path[path.size() - 1].second << std::endl;
    std::cout << std::endl;
    std::cout << "The routes are: " << std::endl;
    for (size_t i = 0; i < path.size(); i++) {
        for (size_t j = i + 1; j < path.size(); j++) {
            for (auto& e : graph.getEdge(path[i].first, path[j].first)) {
                e.printEdge();
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    }
}

void RunIDDFS(Graph graph, Airport from, Airport to, unsigned int max_depth) {
    std::map<Airport, Airport> previous;
    std::vector<Airport> path = IDDFS(graph, from, to, max_depth, previous);
    if (path.empty()) {
        std::cout << "No path found between " << from.airportName_ << " and " << to.airportName_ << " with atmost " << max_depth << " flights" << std::endl;
    } else {
        std::reverse(path.begin(), path.end());
        //calculate total distance
        int totalDistance = 0;
        for (unsigned int i = 0; i < path.size() - 1; i++) {
            totalDistance += graph.getWeight(path[i], path[i + 1]);
        }
        std::cout << "Path between " << from.airportName_ << " and " << to.airportName_ << " with atmost " << max_depth << " flights is: " << std::endl;
        for (unsigned int i = 0; i < path.size(); i++) {
            std::cout << path[i].airportName_;
            if (i != path.size() - 1) std::cout << " -> ";
        }
        std::cout << std::endl;
        std::cout << "The total distance is: " << totalDistance << std::endl;
    }
}

int main()
{
    std::vector<Airport> airports = parseAirports("../tests/data/airports.dat");
    std::vector<Airline> airlines = parseAirlines("../tests/data/airlines.dat");
    std::vector<Edge> routes = parseRoutes("../tests/data/routes.dat");

    Graph graph(airports, airlines, routes);
    
    Airport from = graph.getAirportByIATA("CMI");
    Airport to = graph.getAirportByIATA("LHR");

    //RunDijkstra(graph, from, to);
    RunIDDFS(graph, from, to, 2);



    // hard-coded airlines
    // Airline al1("id1", "n1", "a1", "IATA-A1", "ICAO-A1", "c1", "c1", true);
    // Airline al2("id2", "n2", "a2", "IATA-A2", "ICAO-A2", "c2", "c2", true);
    // Airline al3("id3", "n3", "a3", "IATA-A3", "ICAO-A3", "c3", "c3", true);
    // Airline al4("id4", "n4", "a4", "IATA-A4", "ICAO-A4", "c4", "c4", true);
    // Airline al5("id5", "n5", "a5", "IATA-A5", "ICAO-A5", "c5", "c5", true);
    // std::vector<Airline> airlines = {al1, al2, al3, al4, al5};

    // Airport ap1("id1", "a1", "c1", "c1", "IATA1", "ICAO1", 1, 1, 1, "tz1", "dst1", "tz1", "t1");
    // Airport ap2("id2", "a2", "c2", "c2", "IATA2", "ICAO2", 2, 2, 2, "tz2", "dst2", "tz2", "t2");
    // Airport ap3("id3", "a3", "c3", "c3", "IATA3", "ICAO3", 3, 3, 3, "tz3", "dst3", "tz3", "t3");
    // Airport ap4("id4", "a4", "c4", "c4", "IATA4", "ICAO4", 4, 4, 4, "tz4", "dst4", "tz4", "t4");
    // Airport ap5("id5", "a5", "c5", "c5", "IATA5", "ICAO5", 5, 5, 5, "tz5", "dst5", "tz5", "t5");
    // Airport ap6("id5", "a6", "c6", "c6", "IATA6", "ICAO6", 6, 6, 6, "tz6", "dst6", "tz6", "t6");
    // Airport ap7("id5", "a7", "c7", "c7", "IATA7", "ICAO7", 7, 7, 7, "tz7", "dst7", "tz7", "t7");
    // Airport ap8("id5", "a8", "c8", "c8", "IATA8", "ICAO8", 8, 8, 8, "tz8", "dst8", "tz8", "t8");
    // Airport ap9("id5", "a9", "c9", "c9", "IATA9", "ICAO9", 9, 9, 9, "tz9", "dst9", "tz9", "t9");
    // Airport ap10("id5", "a10", "c10", "c10", "IATA10", "ICAO10", 10, 10, 10, "tz10", "dst10", "tz10", "t10");
    // Airport ap11("id5", "a11", "c11", "c11", "IATA11", "ICAO11", 11, 11, 11, "tz11", "dst11", "tz11", "t11");
    // Airport ap12("id5", "a12", "c12", "c12", "IATA12", "ICAO12", 12, 12, 12, "tz12", "dst12", "tz12", "t12");
    // std::vector<Airport> airports = {ap1, ap2, ap3, ap4, ap5, ap6, ap7, ap8, ap9, ap10, ap11, ap12};

    // Edge e12("al", "id-edge-12", "IATA1", "id1", "IATA2", "id2", true, 1, "t");
    // Edge e13("al", "id", "IATA1", "id1", "IATA3", "id3", true, 1, "t");
    // Edge e24("al", "id", "IATA2", "id2", "IATA4", "id4", true, 1, "t");
    // Edge e34("al", "id", "IATA3", "id3", "IATA4", "id4", true, 1, "t");
    // Edge e49("al", "id", "IATA4", "id4", "IATA9", "id9", true, 1, "t");
    // Edge e16("al", "id", "IATA1", "id1", "IATA6", "id6", true, 1, "t");
    // Edge e68("al", "id-edge-68", "IATA6", "id6", "IATA8", "id8", true, 1, "t");  
    // Edge e67("al", "id", "IATA6", "id6", "IATA7", "id7", true, 1, "t");
    // Edge e510("al", "id", "IATA5", "id5", "IATA10", "id10", true, 1, "t");
    // std::vector<Edge> routes = {e12, e13, e24, e34, e49, e16, e68, e67, e510};

    // // // init graph
    // Graph graph(airports, airlines, routes);
    // for (const auto& e : graph.getEdge(ap1, ap4)) {
    //     std::cout << e.airlineID_ << std::endl;
    // } 
    // //graph.printGraph();

}


/*
Shortest Path between University of Illinois Willard Airport and London Heathrow Airport is: 
University of Illinois Willard Airport -> Chicago O'Hare International Airport -> London Heathrow Airport
The total distance is: 6560

routes from CMI to ORD:
- route 1: 
	airline: 24
	airline id 24
	source airport iataCMI
    source airport id 4049
    dest airport iata ORD
    dest airport id 3830
    does codeshares 1
    number of stops 0
    planetypes ER4 ERD

- route 2: 
    airline: 5265
    airline id 5265
    source airport iataCMI
    source airport id 4049
    dest airport iata ORD
    dest airport id 3830
    does codeshares 0
    number of stops 0
    planetypes ERD ER4


routes from ORD to LHR: 
- route 1:
    airline: 24
    airline id 24
    source airport iataORD
    source airport id 3830
    dest airport iata LHR
    dest airport id 507
    does codeshares 0
    number of stops 0
    planetypes 763 777

- route 2: 
    airline: 2350
    airline id 2350
    source airport iataORD
    source airport id 3830
    dest airport iata LHR
    dest airport id 507
    does codeshares 0
    number of stops 0
    planetypes 763 777 744

- route 3: 
    airline: 1355
    airline id 1355
    source airport iataORD
    source airport id 3830
    dest airport iata LHR
    dest airport id 507
    does codeshares 0
    number of stops 0
    planetypes 744 777

- route 4: 
    airline: 2009
    airline id 2009
    source airport iataORD
    source airport id 3830
    dest airport iata LHR
    dest airport id 507
    does codeshares 1
    number of stops 0
    planetypes 343

- route 5:
    airline: 2822
    airline id 2822
    source airport iataORD
    source airport id 3830
    dest airport iata LHR
    dest airport id 507
    does codeshares 1
    number of stops 0
    planetypes 763 777 744

- route 6:
    airline: 3320
    airline id 3320
    source airport iataORD
    source airport id 3830
    dest airport iata LHR
    dest airport id 507
    does codeshares 1
    number of stops 0
    planetypes 763

- route 7:
    airline: 5209
    airline id 5209
    source airport iataORD
    source airport id 3830
    dest airport iata LHR
    dest airport id 507
    does codeshares 0
    number of stops 0
    planetypes 763

- route 8:
    airline: 5265
    airline id 5265
    source airport iataORD
    source airport id 3830
    dest airport iata LHR
    dest airport id 507
    does codeshares 0
    number of stops 0
    planetypes 763 777

- route 9:
    airline: 5347
    airline id 5347
    source airport iataORD
    source airport id 3830
    dest airport iata LHR
    dest airport id 507
    does codeshares 0
    number of stops 0
    planetypes 343
*/