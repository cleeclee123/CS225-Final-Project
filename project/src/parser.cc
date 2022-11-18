#include "airline.h"
#include "airport.h"

#include <iostream>
#include <fstream>

std::vector<Airport> parseAirports(std::string filename) {
    std::vector<Airport> airports;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
        // std::string code = line.substr(0, 3);
        // std::string name = line.substr(4);
        // airports.push_back(Airport(code, name));
    }
    return airports;
}

std::vector<Airline> parseAirlines(std::string filename) {
    std::vector<Airline> airlines;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        // std::string code = line.substr(0, 3);
        // std::string name = line.substr(4);
        // airlines.push_back(Airline(code, name));
    }
    return airlines;
}

int main() {
    std::vector<Airport> v = parseAirports("airports.dat");
    return 0;
}

