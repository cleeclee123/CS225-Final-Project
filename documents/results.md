# The Written Report

### The output and correctness of each algorithm

  * Dijkstra's Shortest-Path Algorithm
    * Dijkstra's works by starting at a given node, and looping through adjacent nodes, finding connections with the smallest weight
    * We take this previous vector and extract the path from it, based on our from and to Airports
    * The output is a vector of pairs, mapping the Airport to its running distance
        * For example, if we were going from EWR to SFO, and the fastest path included one stop at ORD, then the output would be the following:
            * {{EWR, 0}, {ORD, 100}, {SFO, 500}}
            * The distances are not accurate in the above example, but the idea is that the path, the total path distance, and intermediate distances, are returned. 
    * If there is no path between the from and to Airport, then an empty vector is returned
    * The algorithm is correct since it always finds the shortest path if the airports are connected in some way
    * The runtime will be the same as mentioned in the project proposal: O(|E| + |V|log|V|). All the edges are visited when checking the adjacency list, which explains O(|E|). Additionally, the while loop iterates through the verticies (O|V|); during each iteration, the priority queue is modified (O(log|V|)). 
      * In the context of the project, the while loops continues to check to see if the from and to Airports are matched. If not, edges are cycled through and the edge with less weight is added to the priority queue. 

  * Iterative Deepening Depth First Search Algorithm
    * IDDFS works by starting at a given starting node, and running DFS at increasing depths until the destination is reached
    * The IDDFS integrates a max_depth variable, which serves as a maximum number of flights to reach the destination
    * The output includes a vector of Airports that tracks the path
        * Distances are not included because the purpose of IDDFS is to find a path within a variable number of airports
        * Distances are more relevant for Dijkstra's 
    * If there is no path between the from and to Airport, then an empty vector is returned
    * The algorithm can correctly identify a path within the range provided; however, this path may not be the most optimal
        * Once a path is found, the function returns. To find the most optimal path, Dijsktra's is best. 
    * The run time of IDDFS is identitical to the project proposal. The nodes of the graph each have a different number of edges. Therefore, the worst case time complexity will be O(n) where n is the number of vertices. More specifically, n is the number of vertices within the maximum depth. 
      * In the context of the project, n represents the number of airports within a maximum number of flights. Of course, the time complexity will on average be much less than O(n).
    
  * DFS
    * DFS works by searching down the graph until a leaf-node is reached, and then back-tracking and going across (hence depth-first search)
    * This outputs a path from the start node to the target node
    * Although the path is correct, it is not optimized or special in any way. It simply represents the first found path from the origin to the destination and does not account for weight. 
    * The time complexity of DFS is O(V + E), as all the vertices and edges are visited. This is similar to the project proposal. 
      * Based on our project, V represents the airports and E represents the flights. All airports and flights would be checked in a worst-case scenario. 


### The answer to your leading question 
  * Re-iterating our leading question, Given a dataset of airports and routes, can we find a route between two user-inputed airport codes? Furthermore, if a route does exist, can we find the shortest and valible route? If these conditions are met, and our timeline allows for additonal features, we plan to extend our initial leading question to account for other constraints and parameters. For example, given that a user only wants to fly on Boeing 777 operated by American Airlines from O'Hare to JFK, can we determine if a route exists? 
  * The fundamental goal for this project was to allow the user to find the shortest route between two airports with the additional of extra constraints. We deliver this feature in our main function, where we allow the user to pass in command line arguments of the dataset, source airport, destination airport, airline, and type of plane they want to find. Utilizing object-oriented programming, we abstracted the heavy data-sets into intuitive classes of airports, airlines, and edges (routes). Classes also allowed to build this project in clear steps. We first built a parser to read datasets into the classes along with defining the classes. We then created additional functions specific to each object, such as implementing the Haversine Equation to get the distance between two sets of longitude and latitude coordinates, getters/setters, and comparison operators. Next, we moved to graph construction and implementing traversal and search algorithms. Our grpup opted for an adjacency list representation for performance and implementation reasons. Since we are constructing a graph from a fairly large dataset, our performace of adding a vertex is very important. The time complexity for adding a vertex in an adjacency list is O(1) compared to O(V^2) where V is the number of vertices for an adjacency matrix. The vertices are airport classes, and the edges are edge classes, derived from the routes dataset. Along with graph construction, we created seperate functions to run Dijkstra's Shortest-Path Algorithm and Iterative Deepening Depth First Search Algorithm. We decided to clearly seperate the search algorithms from the graph class. We hope that this improves readability in our codebase. Furthermore, the ability to create m similar graph and pass in into search functions made builing test cases intuitive. We decided to put DFS traversal in the graph class; however, we ran into issues when running dfs multiple time on the same graph. We have a private data member that tracks the traversal. We needed to clear the data member after every traversal/when the starting point was change. Overall, we discovered the direct and real applications of graphs and search algorithms.
