//taliyarial1@gmail.com
#pragma once
#include <iostream>
#include "Graph.hpp"
#include "LinkedList.hpp"

using namespace graph;

const int INF = 1e9;

//This class contain realization of 5 algorithms- BFS, DFS, Dijkstra, Prim, Kroskal.
//The private methods are functions that use by the algorithms.

class Algorithms{
    private:
        int** sort(const Graph& g);
        bool find(int arr[], int arrSize, int var);
        void insertEdges(const Graph& g, LinkedList& queue, int var);
    public:
        Algorithms(){}
        Graph bfs(const Graph& g, int i);
        Graph dfs(const Graph& g, int i);
        Graph dijkstra(const Graph& g, int i);
        Graph prim(const Graph& g);
        Graph kroskal(const Graph& g);
        
};
