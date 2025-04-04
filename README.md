##README FILE- Graph

##Project Overview
This project implements a Graph data structure and various graph algorithms in C++. The project revolves around managing graphs and applying common graph algorithms such as BFS (Breadth-First Search), DFS (Depth-First Search), Dijkstra's algorithm, Prim's Minimum Spanning Tree (MST), and Kruskal's MST. The project is structured into several components that include classes for graph representation, linked list management, and algorithm implementation.
There us also test class for ensuring that the different functionalities work correctly in various scenarios.

##Classes
class: Graph
Class that representing a graph.
The graph has number of vartax, neighbors array and weight array.
The graph is initialized with a specified number of vertices and edges can be added or removed dynamically. The weight of edges is also configurable, with a default value of 1.

Functions:
addEdge(x, y, z): Adds an edge between vertices x and y with an optional weight z.
removeEdge(x, y): Removes an edge between vertices x and y.
print_graph(): Prints the graph to the console.
getVartexNum(): Returns the number of vertices in the graph.
getNeighbors(): Returns the adjacency matrix representing the neighbors.
getWeightArr(): Returns the adjacency matrix representing edge weights.
getWeight(x, y): Returns the weight of the edge between vertices x and y.
getEdgeNum(): Returns the number of edges in the graph.

Class: Node
This class is used to represent a node in a linked list. Each node contains a value and a destination value, and pointer to the next node. Namespace graph include Node class.

Functions:
getNext(): Returns the next node in the list.
getValue(): Returns the value of the current node.
getDest(): Returns the destination value of the node.

class: LinkedList
This class manages a linked list, which can be used for various purposes, including implementing queues, priority queues, and stacks. Namespace graph include LinkedList class.

Functions:
addNode(Node* n): Adds a node to the linked list.
removeLastNode(): Removes and returns the last node in the list.
isEmpty(): Checks if the list is empty.
removeFirstNode(): Removes and returns the first node in the list.
removePriority(): Removes a node based on priority.

Class: Algorithms
This class contains the implementation of  graph algorithms: BFS, DFS, Prim, Dijkstra, Kruskal.

Functions:
bfs(g, i): Performs a breadth-first search starting from vertex i.
dfs(g, i): Performs a depth-first search starting from vertex i.
dijkstra(g, i): Performs Dijkstra's algorithm starting from vertex i to find the shortest paths.
prim(g): Computes the Minimum Spanning Tree (MST) of the graph using Prim’s algorithm.
kroskal(g): Computes the Minimum Spanning Tree (MST) of the graph using Kruskal’s algorithm.

Class: Test
The project uses the test class to test the correctness of the graph functionalities and algorithms by different test cases.

##Setup and Compilation
To compile and run the project, follow these steps:
1. Clone the repository.
2. Compile the code Use a C++ compiler.
3. Options: 
make Main- to run the demo file.
make test- to run the unit test.
make valgrind- memory leak testing using valgrind.
make clean- deletes all irrelevant files after running.