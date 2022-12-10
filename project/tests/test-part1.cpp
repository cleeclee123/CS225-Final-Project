#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <parser.h>

// test split function
TEST_CASE("split function", "[weight=1][part=1]") {
    std::string line = "1,2,3,4,5,6,7,8,9,10,11,12,13,14";
    std::vector<std::string> tokens = split(line, ',');
    REQUIRE(tokens.size() == 14);
    REQUIRE(tokens[0] == "1");
    REQUIRE(tokens[1] == "2");
    REQUIRE(tokens[2] == "3");
    REQUIRE(tokens[3] == "4");
    REQUIRE(tokens[4] == "5");
    REQUIRE(tokens[5] == "6");
    REQUIRE(tokens[6] == "7");
    REQUIRE(tokens[7] == "8");
    REQUIRE(tokens[8] == "9");
    REQUIRE(tokens[9] == "10");
    REQUIRE(tokens[10] == "11");
    REQUIRE(tokens[11] == "12");
    REQUIRE(tokens[12] == "13");
    REQUIRE(tokens[13] == "14");
}

TEST_CASE("parseAirport function", "[weight=1][part=1]") {
    std::string line = "1,\"Goroka\",\"Goroka\",\"Papua New Guinea\",\"GKA\",\"AYGA\",-6.081689834590001,145.391998291,5282,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"";
    std::vector<Airport> airports = parseAirports(line);
    REQUIRE(airports.size() == 1);
    REQUIRE(airports[0].getAirportID() == "1");
    REQUIRE(airports[0].getAirportName() == "Goroka");
    REQUIRE(airports[0].getCityName() == "Goroka");
    REQUIRE(airports[0].getCountry() == "Papua New Guinea");
    REQUIRE(airports[0].getIATA() == "GKA");
    REQUIRE(airports[0].getICAO() == "AYGA");
    REQUIRE(airports[0].getLatitude() == -6.081689834590001);
    REQUIRE(airports[0].getLongitude() == 145.391998291);
    REQUIRE(airports[0].getAltitude() == 5282);
    REQUIRE(airports[0].getTimezone() == "10");
    REQUIRE(airports[0].getDst() == "U");
    REQUIRE(airports[0].getTz() == "Pacific/Port_Moresby");
}

TEST_CASE("parseAirline function", "weight=1][part=1]") {
    std::string line = "1,\"Private flight\",\"\",\"\",\"\",\"\",\"Y\",\"\"";
    std::vector<Airline> airlines = parseAirlines(line);
    REQUIRE(airlines.size() == 1);
    REQUIRE(airlines[0].getAirlineID() == "1");
    REQUIRE(airlines[0].getName() == "Private flight");
    REQUIRE(airlines[0].getAlias() == "");
    REQUIRE(airlines[0].getIATA() == "");
    REQUIRE(airlines[0].getICAO() == "");
    REQUIRE(airlines[0].getCallsign() == "");
    REQUIRE(airlines[0].getCountry() == "Y");
    REQUIRE_FALSE(airlines[0].getIsActive());

    std::string line2 = "2,\"135 Airways\",\"\",\"GNL\",\"GENERAL\",\"GENERAL AIRLINES\",\"Y\",\"\"";
    std::vector<Airline> airlines2 = parseAirlines(line2);
    REQUIRE(airlines2.size() == 1);
    REQUIRE(airlines2[0].getAirlineID() == "2");
    REQUIRE(airlines2[0].getName() == "135 Airways");
    REQUIRE(airlines2[0].getAlias() == "");
    REQUIRE(airlines2[0].getIATA() == "GNL");
    REQUIRE(airlines2[0].getICAO() == "GENERAL");
    REQUIRE(airlines2[0].getCallsign() == "GENERAL AIRLINES");
    REQUIRE(airlines2[0].getCountry() == "Y");
    REQUIRE_FALSE(airlines2[0].getIsActive());

    std::string line3 = "3,\"1Time Airline\",\"1Time Airline\",\"RNX\",\"NEXTIME\",\"NEXTIME AIRLINES\",\"N\",\"Y\"";
    std::vector<Airline> airlines3 = parseAirlines(line3);
    REQUIRE(airlines3.size() == 1);
    REQUIRE(airlines3[0].getAirlineID() == "3");
    REQUIRE(airlines3[0].getName() == "1Time Airline");
    REQUIRE(airlines3[0].getAlias() == "1Time Airline");
    REQUIRE(airlines3[0].getIATA() == "RNX");
    REQUIRE(airlines3[0].getICAO() == "NEXTIME");
    REQUIRE(airlines3[0].getCallsign() == "NEXTIME AIRLINES");
    REQUIRE(airlines3[0].getCountry() == "N");
    REQUIRE(airlines3[0].getIsActive());
}

TEST_CASE("parseRoute function", "[weight=1][part=1]") {
    std::string line = "2B,410,AER,2965,KZN,2990,,0,CR2";
    std::vector<Edge> routes = parseRoutes(line);
    REQUIRE(routes.size() == 1);
    REQUIRE(routes[0].getAirline() == "2B");
    REQUIRE(routes[0].getAirlineID() == "410");
    REQUIRE(routes[0].getSrcIATA() == "AER");
    REQUIRE(routes[0].getSrcID() == "2965");
    REQUIRE(routes[0].getDestIATA() == "KZN");
    REQUIRE(routes[0].getDestIATA() == "2990");
    REQUIRE_FALSE(routes[0].getCodeshare());
    REQUIRE(routes[0].getStops() == 0);
    REQUIRE(routes[0].getPlaneTypes() == "CR2");
}