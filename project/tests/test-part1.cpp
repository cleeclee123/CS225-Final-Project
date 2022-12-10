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
    std::vector<Airport> airports = parseAirports("../tests/data/airport_test.dat");
    REQUIRE(airports.size() == 7);
    REQUIRE(airports[0].getAirportID() == "148");
    REQUIRE(airports[0].getAirportName() == "Hall Beach Airport");
    REQUIRE(airports[0].getCityName() == "Hall Beach");
    REQUIRE(airports[0].getCountry() == "Canada");
    REQUIRE(airports[0].getIATA() == "YUX");
    REQUIRE(airports[0].getICAO() == "CYUX");
    REQUIRE(airports[0].getLatitude() == 68.77610015869999);
    REQUIRE(airports[0].getLongitude() == -81.2425);
    REQUIRE(airports[0].getAltitude() == 30);
    REQUIRE(airports[0].getTimezone() == "-5");
    REQUIRE(airports[0].getDst() == "A");
    REQUIRE(airports[0].getTz() == "America/Toronto");
    REQUIRE(airports[0].getType() == "airport");
}

TEST_CASE("parseAirline function", "[weight=1][part=1]") {
    std::vector<Airline> airlines = parseAirlines("../tests/data/airline_test.dat");
    REQUIRE(airlines.size() == 5);
    REQUIRE(airlines[0].getAirlineID() == "2");
    REQUIRE(airlines[0].getName() == "135 Airways");
    REQUIRE(airlines[0].getAlias() == "");
    REQUIRE(airlines[0].getIATA() == "");
    REQUIRE(airlines[0].getICAO() == "GNL");
    REQUIRE(airlines[0].getCallsign() == "GENERAL");
    REQUIRE(airlines[0].getCountry() == "United States");
    REQUIRE_FALSE(airlines[0].getIsActive());
}

TEST_CASE("parseRoute function", "[weight=1][part=1]") {
    std::vector<Edge> routes = parseRoutes("../tests/data/route_test.dat");
    REQUIRE(routes.size() == 6);
    REQUIRE(routes[0].getAirline() == "UA");
    REQUIRE(routes[0].getAirlineID() == "5209");
    REQUIRE(routes[0].getSrcIATA() == "DEN");
    REQUIRE(routes[0].getSrcID() == "3751");
    REQUIRE(routes[0].getDestIATA() == "SGU");
    REQUIRE(routes[0].getDestID() == "4064");
    REQUIRE(routes[0].getCodeshare());
    REQUIRE(routes[0].getStops() == 0);
    REQUIRE(routes[0].getPlaneTypes() == "CRJ");
}