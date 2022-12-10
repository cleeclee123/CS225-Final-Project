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

// test parseAirport function
TEST_CASE("parseAirport function", "[weight=1][part=1]") {
    std::string line = "1,\"Goroka\",\"Goroka\",\"Papua New Guinea\",\"GKA\",\"AYGA\",-6.081689834590001,145.391998291,5282,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"";
    Airport airport = parseAirport(line);
    REQUIRE(airport.getID() == "1");
    REQUIRE(airport.getName() == "Goroka");
    REQUIRE(airport.getCity() == "Goroka");
    REQUIRE(airport.getCountry() == "Papua New Guinea");
    REQUIRE(airport.getIATA() == "GKA");
    REQUIRE(airport.getICAO() == "AYGA");
    REQUIRE(airport.getLatitude() == -6.081689834590001);
    REQUIRE(airport.getLongitude() == 145.391998291);
    REQUIRE(airport.getAltitude() == 5282);
    REQUIRE(airport.getTimezone() == "10");
    REQUIRE(airport.getDST() == "U");
    REQUIRE(airport.getTZ() == "Pacific/Port_Moresby");
}

// test parseAirline function
TEST_CASE("parseAirline function", "weight=1][part=1]") {
    std::string line = "1,\"Private flight\",\"\",\"\",\"\",\"\",\"Y\",\"\"";
    Airline airline = parseAirline(line);
    REQUIRE(airline.getID() == "1");
    REQUIRE(airline.getName() == "Private flight");
    REQUIRE(airline.getAlias() == "");
    REQUIRE(airline.getIATA() == "");
    REQUIRE(airline.getICAO() == "");
    REQUIRE(airline.getCallSign() == "");
    REQUIRE(airline.getCountry() == "Y");
    REQUIRE(airline.getActive() == "");

    std::string line = "2,\"135 Airways\",\"\",\"GNL\",\"GENERAL\",\"GENERAL AIRLINES\",\"Y\",\"\"";
    Airline airline = parseAirline(line);
    REQUIRE(airline.getID() == "2");  
    REQUIRE(airline.getName() == "135 Airways");
    REQUIRE(airline.getAlias() == "");
    REQUIRE(airline.getIATA() == "GNL");
    REQUIRE(airline.getICAO() == "GENERAL");
    REQUIRE(airline.getCallSign() == "GENERAL AIRLINES");
    REQUIRE(airline.getCountry() == "Y");
    REQUIRE(airline.getActive() == "");

    std::string line = "3,\"1Time Airline\",\"1Time Airline\",\"RNX\",\"NEXTIME\",\"NEXTIME AIRLINES\",\"N\",\"Y\"";
    Airline airline = parseAirline(line);
    REQUIRE(airline.getID() == "3");
    REQUIRE(airline.getName() == "1Time Airline");
    REQUIRE(airline.getAlias() == "1Time Airline");
    REQUIRE(airline.getIATA() == "RNX");
    REQUIRE(airline.getICAO() == "NEXTIME");
    REQUIRE(airline.getCallSign() == "NEXTIME AIRLINES");
    REQUIRE(airline.getCountry() == "N");
    REQUIRE(airline.getActive() == "Y");
}

// test parseRoute function
TEST_CASE("parseRoute function", "[weight=1][part=1]") {
    std::string line = "2B,410,AER,2965,KZN,2990,,0,CR2";
    Route route = parseRoute(line);
    REQUIRE(route.getAirline() == "2B");
    REQUIRE(route.getAirlineID() == "410");
    REQUIRE(route.getSource() == "AER");
    REQUIRE(route.getSourceID() == "2965");
    REQUIRE(route.getDestination() == "KZN");
    REQUIRE(route.getDestinationID() == "2990");
    REQUIRE(route.getCodeshare() == "");
    REQUIRE(route.getStops() == "0");
    REQUIRE(route.getEquipment() == "CR2");
}