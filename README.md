# Team SAC | Siya Digra (sdigra2), Areet Sheth (assheth2), Christopher Lee (cl114)
# CS 225 Final Project Fall 2022

## [Video Presentation of Project]()
## Table of Contents
* [Documentation](https://github.com/cleeclee123/CS225-Final-Project#documentation)
* [Installation](https://github.com/cleeclee123/CS225-Final-Project#installation)
* [Features](https://github.com/cleeclee123/CS225-Final-Project#features)
* [How to Build (with execution examples)](https://github.com/cleeclee123/CS225-Final-Project#how-to-build-with-execution-examples)
* [Testing](https://github.com/cleeclee123/CS225-Final-Project#testing)
* [Project Structure](https://github.com/cleeclee123/CS225-Final-Project#project-structure)

## Documentation
* #### Goals
  * Link to Project Proposal can be found [Here](https://github.com/cleeclee123/CS225-Final-Project/blob/main/documents/project-proposal.md)

* #### Development
  * Link to Development Documentation can be found [Here](https://github.com/cleeclee123/CS225-Final-Project/tree/main/dev-logs)

* #### Team Contracts
  * Link to Team Contracts can be found [Here](https://github.com/cleeclee123/CS225-Final-Project/blob/main/documents/team-contract.md)

* #### Results
  * Link to Results can be found [Here](https://github.com/cleeclee123/CS225-Final-Project/blob/main/documents/results.md)

## Installation

To setup this project, clone the repository locally using the command
```bash
git clone https://github.com/cleeclee123/CS225-Final-Project.git
```
then cd into the newly made directory to be able to utilize the commands in the <a href="https://github.com/cleeclee123/CS225-Final-Project#how-to-build"><strong> How to Build </strong></a> section.

## How to Build (with execution examples)

To build the file, use the command:
```bash
make
```

There are 4 main commands that can be run after building the main executable from the main command:
```bash
./main parser [airport file] [airline file] [routes file]
./main dijkstra0 [src airport IATA] [dest airport IATA]
./main iddfs0 [src airport IATA] [dest airport IATA] [number of layovers]
./main extra0 [src airport IATA] [dest airport IATA] [airline] [airplane]
./main dfs0 [starting airport IATA]
./main dijkstra1 [airport file] [airline file] [routes file] [src airport IATA] [dest airport IATA]
./main iddfs1 [airport file] [airline file] [routes file] [src airport IATA] [dest airport IATA] [number of layovers]
./main extra1 [airport file] [airline file] [routes file] [src airport IATA] [dest airport IATA] [airline] [airplane]
./main dfs1 [airport file] [airline file] [routes file] [starting airport]
```
The command `./main` will default to a prompt, similar to what you see above, listing all of the available commands.
The commands followed by "0" runs the respective algorithm/feature on a the entire Open Flights datasets: airports.dat, airline.dat, routes.dat
The commands followed by "1" runs the respective algorithm/feature on the datasets passed in as argv[0] to argv[1]

Checking for memory leaks: 
```bash 
valgrind --leak-check=full ./main
```

## Testing

The code provides a wide variety of tests for the various functions within the program. To run them and see the resulting account of success and failure use the command:
```bash
make test
```
to build them, and then run the test executible using:
```bash
./test
```
The tests that will be run are located within the tests folder of the project. We have included visualizations of the graphs in the tests folder. /

This command will specifically run the data cleaning/parser test cases.
```bash
./test [part=1]
```

This command will specifically run the graph construction test cases.
```bash
./test [part=2]
```

This command will specifically run the search algorithm test cases.
```bash
./test [part=3]
```

This command will specifically run DFS test cases.
```bash
./test [part=4]
```

## Project Structure and Features

* #### Preprocessing/Parser (Siya)
  * Airport parser
  * Airline parser
  * Routes parser

* #### Objects (Chris)
  * Graph class
  * Airport class
  * Airline class
  * Routes class
  
* #### Algorithms (Areet)
  * Dijkstra's Shortest-Path Algorithm
  * Iterative Deepening Depth First Search Algorithm
  * DFS
 

#### Structure of README.md taken from [Here](https://github.com/zeh3/wikipedia-game)