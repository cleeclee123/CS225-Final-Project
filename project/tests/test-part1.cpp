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
   
}

TEST_CASE("parseRoute function", "[weight=1][part=1]") {
    
}