## Leading Question 
Given a dataset of airports and routes, can we find a route between two user-inputed airport codes? Furthermore, if a route does exist, can we find the shortest and valible route? If these conditions are met, and our timeline allows for additonal features, we plan to extend our initial leading question to account for other constraints and parameters. For example, given that a user only wants to fly on Boeing 777 operated by American Airlines from O'Hare to JFK, can we determine if a route exists?

## Dataset Acquisition
To answer this question, our group will be leveraging datasets from OpenFlights, specfically airports.dat (https://raw.githubusercontent.com/jpatokal/openflights/master/data/airports.dat) and routes.dat (https://raw.githubusercontent.com/jpatokal/openflights/master/data/routes.dat). The first dataset, airports.dat, will serve as nodes in our traversal graph. The second dataset, routes.dat, will allow our group to determine if a path exists between the node derived from the first dataset. Moreover, as touched on above in the Leading Questions section, we have the option to use other datasets to satify additional constraints and parameters. For example, OpenFlights' planes.dat and airlines.dat datasets. Our data acquisition process will include downloading the publicly avaliable datasets from https://openflights.org/data.html as a CSV. 

## Data Format
After our data acquisition process, the initial datasets are in CSV format. We can use third-party tools to format the datasets into JSON for exploratory data analysis. While a proper ETL pipeline is a bit overkill for this final project, we plan on building a parser and cleaner for out inital data to transform into Airport objects and the graph as a whole. The cleaning process consists on ignoring null values when reading in our Airport object. 

## Data Correction
If data correction is needed, then we will take the steps to ensure that our datasets are accurate or that our parser accounts for incorrectness. In our parser, we will have null checks, ignoring this value when reading into our Airport class. However, this invite an additional issue of a missing value. In such cases, our group will manually check these values and correct them by hand. Furthermore, our group will remove any edges that are not complete where both nodes exist in the dataset. 

## Data Storage
We will create a Airport object containing information about the Airport such as the airport id, number of incoming and outgoing traffic, name, city, latitude, longitude, altitude, and additional- perhaps more dynamics- constraints like weather and geopolitical tensions (we can elaborate more with our mentor). The Airport object will serve as the node in our graph. For this final project, our group discussed the tradeoffs between an adjacency list implementation from a adjacency matrix implenmentation. We have decided to opt to use an adjacency list representation for performance and implementation reasons. Since we are constructing a graph from a fairly large dataset, our performace of adding a vertex is very important. The time complexity for adding a vertex in an adjacency list is O(1) compared to O(V^2) where V is the number of vertices for an adjacency matrix. The edge of our graph will be derived from the routes dataset. We will use weighted edges, where the weight represents the distance between two airports. The distance is calculated given the Latitude Longitude of two airports. We will reference this implementation https://www.geeksforgeeks.org/program-distance-two-points-earth/

## Algorithm 

Traversal: Breadth-first search

Search: Dijkstra's algorithm & Iterative Deepending DFS Algorithm

The inputs given to our implementation of Dijkstra's algorithm & the Iterative Deepending DFS algorithm will the airport code of the starting airport and the airport code of the desire destination. The output will be a boolean value that a route exists and if multiple nodes are traversed, then an array of Airport Objects that represent the shortest path from the starting airport to the destination airport. 

The time complexity of Breadth-first search is O(V + E) for our adjacency list implementation where V is the number of vertices (airports) and E is the number of edges (routes). The space complexity of Breadth-first search is O(|V|) where V is the total number of vertices in our graph. In other words, in the worst case we have to hold all airports in our queue during travsersal. 

In Dijkstra's algorithm, each edge is viewed at most two times: O|E|. Each node is viewed at most two times, once to enqueue and once to query. Enqueue takes constant time O|V| and querying takes logarithmic time O(log|V|) because we will be using a binary heap as our priority queue. The resulting time complexity is: O(|E| + |V|log|V|). The space complexity of Dijkstra's algorithm is O(|V| + |E|) where V is the number of vertices (airports) and E is the number of edges (routes). 

In the iterative deepening DFS algorithm (IDDFS), DFS is continuously run with increasing limits unil the goal is reached. IDDFS has the space efficiecy of DFS and the order nodes are visited from BFS. In this case, the time complexity is O(2^h) where d is the height of the target. This is the worst case scenario in a fully-balanced tree. The space complexity is O(h) where h is also the height of the target. IDDFS only needs to add the most optimal nodes to the stack, h is the optimal solution height. 


## Timeline
Week 0 (10/31 - 11/04): 
- Onboarding stuff
- Team Contract & Project Proposal

Week 1 (11/07 - 11/11):
- Dataset Acquisition
- Data Correction
  - Start of data processing 
    - cleaning
  - exploratory data analysis

Week 2 (10/14 - 11/18):
- Data Storage
  - Create Airport Class
  - Adjacency List Implementation

Week 3 (10/21 - 11/25):
- Data Storage
  - Reading data into graph

Week 4 (10/28 - 12/02):
- Testing

Week 5 (12/05 - 12/09):
- Final Presentation

Week 6 (12/09 - 12/13):
- Leeway
