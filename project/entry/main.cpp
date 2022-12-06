#include <iostream>
#include "parser.h"

int main()
{
    std::cout << "Hello World!" << std::endl;
    std::vector<Airport> v = parseAirports("/workspaces/siya/UIUC/cs225/CS225-Final-Project/project/tests/data/airports.dat");
    std::vector<Airline> v2 = parseAirlines("/workspaces/siya/UIUC/cs225/CS225-Final-Project/project/tests/data/airlines.dat");
    std::vector<Edge> v3 = parseRoutes("/workspaces/siya/UIUC/cs225/CS225-Final-Project/project/tests/data/routes.dat");
    return 0;
}