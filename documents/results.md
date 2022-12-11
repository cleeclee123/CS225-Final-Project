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

  * Iterative Deepening Depth First Search Algorithm
    * IDDFS works by starting at a given starting node, and running DFS at increasing depths until the destination is reached
    * The IDDFS integrates a max_depth variable, which serves as a maximum number of flights to reach the destination
    * The output includes a vector of Airports that tracks the path
        * Distances are not included because the purpose of IDDFS is to find a path within a variable number of airports
        * Distances are more relevant for Dijkstra's 
    * If there is no path between the from and to Airport, then an empty vector is returned
    * The algorithm can correctly identify a path within the range provided; however, this path may not be the most optimal
        * Once a path is found, the function returns. To find the most optimal path, Dijsktra's is best. 
    
  * DFS
    * DFS works by searching down the graph until a leaf-node is reached, and then back-tracking and going across (hence depth-first search)
    * This outputs a path from the start node to the target node
    * Although the path is correct, it is not optimized or special in any way. It simply represents the first found path from the origin to the destination and does not account for weight. 



### The answer to your leading question 
