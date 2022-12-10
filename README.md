# Team SAC | Siya Digra (sdigra2), Areet Sheth (assheth2), Christopher Lee (cl114)
# CS 225 Final Project Fall 2022

## [Video Presentation of Project]()
## Table of Contents
* [Documentation](https://github.com/cleeclee123/CS225-Final-Project#documentation)
* [Installation](https://github.com/cleeclee123/CS225-Final-Project#installation)
* [How to Build (with execution examples)](https://github.com/cleeclee123/CS225-Final-Project#how-to-build)
* [Testing](https://github.com/cleeclee123/CS225-Final-Project#testing)
* [Project Structure](https://github.com/cleeclee123/CS225-Final-Project#project-structure)
* [Features](https://github.com/cleeclee123/CS225-Final-Project#features)

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

## How to Build

The following description has been modified from CS225 MP documentation. 

Preparing the Codebase:
This project uses CMake. This allows for us to use libraries such as Catch2 that can be installed in our system rather than providing them specifcally in each project. This means that we need to use CMake to build our own custom makefiles. To do this we need to run the following in the base directory of the project. Which in this project is the CS225-Final-Project directory (or whatever you have have named it).
```bash
mkdir build
cd build
```

This first makes a new directory in your assignment directory called build. This is where you will actually build the assignment and then moves to that directory. This is not included in the provided code since we are following industry standard practices and you would normally exclude the build directory from any source control system.
Now you need to actually run CMake as follows.
```bash
cmake ..
```
This runs CMake to initialize the current directory which is the build directory you just made as the location to build the assignment. The one argument to CMake here is .. which referes to the parent of the current directory which in this case is top of the assignment. This directory has the files CMake needs to setup your assignment to be build. You will need to run make every time you change source code and want to compile it again.

To build the file, use the command:
```bash
make main
```

There are 4 main commands that can be run after building the main executable from the main command:
```bash
./main default
./main parser [airport file] [airline file] [routes file]
./main dijkstra0 [src airport IATA] [dest airport IATA]
./main iddfs0 [src airport IATA] [dest airport IATA] [number of layovers]
./main extra0 [src airport IATA] [dest airport IATA] [airline] [airplane]
./main dfs0 [starting airport IATA]
./main dijkstra1 [airport file] [airline file] [routes file] [src airport IATA] [dest airport IATA]
./main iddfs1 [airport file] [airline file] [routes file] [src airport IATA] [dest airport IATA] [number of layovers]
./main extra1 [airport file] [airline file] [routes file] [src airport IATA] [dest airport IATA] [airline] [airplane]
./main dfs1 [airport file] [airline file] [routes file] [starting airport]
./main dontrunthis
```
The command `./main` will default to a prompt, similar to what you see above, listing all of the available commands.
The command `./main default` is suggested to be run first. This gives a demo of what we have built. Specifically, this tests the shortest route avaliable from Willard Airport to London Heathrow Airport on a Boeing 747 operated by American Airlines. 
The commands followed by "0" runs the respective algorithm/feature on a the entire Open Flights datasets: airports.dat, airline.dat, routes.dat.
The commands followed by "1" runs the respective algorithm/feature on the datasets passed in as argv[0] to argv[1].
Executing the last command is at your own risk, you have been warned.

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

## Project Structure:
* The codebase can be found in `/projects`  [Here](https://github.com/cleeclee123/CS225-Final-Project/tree/main/project)
  * In our codebase, tests and datasets can be found in `/tests`
  * The main function is found in the entry directory, `/entry`
  * `/src` contains all of our code for the parser, objects, and algorithms
  * The `/lib` has been copied over from mp_schedule
* Our Development Log can be founds in `/dev-logs`  [Here](https://github.com/cleeclee123/CS225-Final-Project/tree/main/dev-logs)
* Our Project Documentation can be founds in `/documents`  [Here](https://github.com/cleeclee123/CS225-Final-Project/tree/main/dev-logs)

## Features: 
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
    * Finds a path between a "from" and "to" airport
    * Path found will be the shortest in terms of distance
    * If two airports are unconnected, empty return
  * Iterative Deepening Depth First Search Algorithm
    * Finds a path between a "from" and "to" airport
    * May not be shortest path b/c does not account for edge weight
    * Works as a combination of DFS and BFS
      * Runs DFS at incrementing depths
    * Restricted by a max depth, which represents the number of flights the path can take
    * If two airports are unconnected or path outside of max depth, empty return 
  * DFS
    * Searches graph to find path between 
    * Does not account for edge weights
    * First searches down, and then across, hence depth-first search
 

#### The structure of this README.md was heavily inspired from [Here](https://github.com/zeh3/wikipedia-game)
