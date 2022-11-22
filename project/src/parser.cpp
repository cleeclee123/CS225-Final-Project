#include "airline.h"
#include "airport.h"

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

std::vector<std::string> split(std::string line, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(line);
    while (std::getline(tokenStream, token, delimiter)) {
        if (token == "\\N") {
            token = "";
        }
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<Airport> parseAirports(std::string filename) {
    std::vector<Airport> airports;
    std::ifstream ifs(filename);
    while (ifs.good()) {
        std::string line;
        std::getline(ifs, line);
        if (line.empty()) {
            continue;
        }

        std::vector<std::string> data = split(line, ',');
        if (data.size() != 14) {
            continue;
        }
        
        std::string airportID = data[0];

        std::string airportName = data[1];
        if (airportName[0] == '"') {
            airportName = airportName.substr(1, airportName.size() - 2);
        }

        std::string cityName = data[2];
        if (cityName[0] == '"') {
            cityName = cityName.substr(1, cityName.size() - 2);
        }

        std::string country = data[3];
        if (country[0] == '"') {
            country = country.substr(1, country.size() - 2);
        }

        std::string IATA = data[4];
        if (IATA[0] == '"') {
            IATA = IATA.substr(1, IATA.size() - 2);
        }

        std::string ICAO = data[5];
        if (ICAO[0] == '"') {
            ICAO = ICAO.substr(1, ICAO.size() - 2);
        }

        if (data[6] == "") {
            data[6] = "0";
        }
        double latitude = std::stod(data[6]);

        if (data[7] == "") {
            data[7] = "0";
        }
        double longitude = std::stod(data[7]);

        if (data[8] == "") {
            data[8] = "0";
        }
        unsigned altitude = std::stod(data[8]);

        std::string timezone = data[9];
        if (timezone[0] == '"') {
            timezone = timezone.substr(1, timezone.size() - 2);
        }

        std::string dst = data[10];
        if (dst[0] == '"') {
            dst = dst.substr(1, dst.size() - 2);
        }

        std::string tz = data[11];
        if (tz[0] == '"') {
            tz = tz.substr(1, tz.size() - 2);
        }

        std::string type = data[12];
        if (type[0] == '"') {
            type = type.substr(1, type.size() - 2);
        }

        Airport airport(airportID, airportName, cityName, country, IATA, ICAO, latitude, longitude, altitude, timezone, dst, tz, type);
        airports.push_back(airport);
    }
    return airports;
}

std::vector<Airline> parseAirlines(std::string filename) {
    std::vector<Airline> airlines;
    std::ifstream ifs(filename);
    while (ifs.good()) {
        std::string line;
        std::getline(ifs, line);
        if (line.empty()) {
            continue;
        }

        std::vector<std::string> data = split(line, ',');
        if (data.size() != 8) {
            continue;
        }

        std::string airlineID = data[0];

        std::string name = data[1];
        if (name[0] == '"') {
            name = name.substr(1, name.size() - 2);
        }

        std::string alias = data[2];
        if (alias[0] == '"') {
            alias = alias.substr(1, alias.size() - 2);
        }

        std::string IATA = data[3];
        if (IATA[0] == '"') {
            IATA = IATA.substr(1, IATA.size() - 2);
        }

        std::string ICAO = data[4];
        if (ICAO[0] == '"') {
            ICAO = ICAO.substr(1, ICAO.size() - 2);
        }

        std::string callsign = data[5];
        if (callsign[0] == '"') {
            callsign = callsign.substr(1, callsign.size() - 2);
        }

        std::string country = data[6];
        if (country[0] == '"') {
            country = country.substr(1, country.size() - 2);
        }

        std::string activeS = data[7];
        if (activeS[0] == '"') {
            activeS = activeS.substr(1, activeS.size() - 2);
        }
        bool active;
        if (activeS == "Y") {
            active = true;
        } else {
            active = false;
        }

        Airline airline(airlineID, name, alias, IATA, ICAO, callsign, country, active);
        airlines.push_back(airline);
    }
    return airlines;
}

