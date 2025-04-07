//taliyarial1@gmail.com
#pragma once

#include <iostream>

//This class represent a Graph.
//The graph has number of vartax, neighbors array and weight array.

class Graph{
    private:
        int vartexNum;
        int** neighbors;
        int** weight;
    
    public:
        Graph(int x);
        ~Graph();
        void addEdge(int x, int y, int z = 1);
        void removeEdge(int x, int y);
        void print_graph_weight(std::string s);
        void print_graph(std::string s);
        int getVartexNum()const{return this->vartexNum;} //Function that return the number of vartax in the graph.
        int** getNeighbors()const{return this->neighbors;} //Function that return the graph neighbors array.
        int** getWeightArr()const{return this->weight;} //Function that return the graph weight array.
        int getWeight(int x, int y)const;
        int getEdgeNum()const;
};