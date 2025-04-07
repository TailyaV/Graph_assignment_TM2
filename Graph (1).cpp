//taliyarial1@gmail.com
#include <iostream>
#include "Graph.hpp"
#include "LinkedList.hpp"
#include <stdexcept>

using namespace graph;

//Graph constractor- allocate memory for neighbors array and weight array and fill them with zero.
Graph::Graph(int x){
    vartexNum = x;
    neighbors = new int*[x];
    int edges = x * (x -1);
    weight = new int*[edges];
    for(int i = 0; i < vartexNum; i = i + 1){
        neighbors[i] = new int[x - 1];
    }
    for(int i = 0; i < vartexNum; i = i + 1){
        for(int j = 0; j < vartexNum - 1; j++){
            neighbors[i][j] = 0;
        }
    }
    for(int i = 0; i < edges; i = i + 1){
        weight[i] = new int[3];
    }
    for(int i = 0; i < edges; i = i + 1){
        for(int j = 0; j < 3; j++){
            weight[i][j] = 0;
        }
    }
}


//Graph distractor- free the alocated memory of neighbors array and weight array.
Graph::~Graph(){
    int edges = vartexNum * (vartexNum -1);
    for(int i = 0; i < vartexNum; i = i + 1){
        delete[] neighbors[i];
    }
    delete[] neighbors;
    for(int i = 0; i < edges; i = i + 1){
        delete[] weight[i];
    }
    delete[] weight;
}

//Function for add edges to the graph by adding them to the graph arrays, if weight is not given- the difult is 1.
void Graph::addEdge(int src, int dst, int w){
    int flag = 0;
    int edges = vartexNum * (vartexNum -1);
    if(src > vartexNum || dst > vartexNum || src < 1 || dst < 1){
        throw std::invalid_argument("unexisted vartex");
    }
    for(int i = 0; i < vartexNum - 1; i++){
        if(neighbors[src - 1][i] == dst){
            std::cout << "This edge is olready exist" << std::endl;
            flag = 1;
            break;
        }
        if(neighbors[src - 1][i] == 0){
            neighbors[src - 1][i] = dst;
            break;
        }
    }
    if(flag == 0){
        for(int i = 0; i < vartexNum - 1; i++){
            if(neighbors[dst - 1][i] == 0){
                neighbors[dst - 1][i] = src;
                break;
            }
        }
        int i = 0;
        while (weight[i][0] != 0){
            i++;
        }
        if(i < edges){
            weight[i][0] = src;
            weight[i][1] = dst;
            weight[i][2] = w;
        }
    }

}

//Function for remove edges from the graph, by removing them from the graph arrays.
void Graph::removeEdge(int x, int y){
    int flag = 0;
    int edges = vartexNum * (vartexNum -1);
    for(int i = 0; i < vartexNum - 1; i++){
        if(neighbors[y - 1][i] == x){
            neighbors[y - 1][i] = 0;
        }
        if(neighbors[x - 1][i] == y){
            neighbors[x - 1][i] = 0;
            flag = 1;
        }
    }
    if(flag == 0){
        throw std::invalid_argument("invalide argument, edge dosent exsist");
    }

    for(int i = 0; i < edges; i++){
        if((weight[i][0] == x && weight[i][1] == y) || (weight[i][0] == y && weight[i][1] == x)){
            weight[i][0] = 0;
            weight[i][1] = 0;
            weight[i][2] = 0;
        }

    }
}

//Function for printing the graph vartaxs and weight. 
void Graph::print_graph_weight(std::string s){
    int edges = vartexNum * (vartexNum -1);
    std::cout << s << " graph is: " << std::endl;
    for(int j = 0; j < edges; j++){
        int x = this->weight[j][0];
        int y = this->weight[j][1];
        if(x != 0 && y != 0){
            std::cout << "(" << x << "," << y << ")";
            for(int i = 0; i < edges; i++){
                if((weight[i][0] == x && weight[i][1] == y) || (weight[i][0] == y && weight[i][1] == x)){
                    std::cout << " Weight: " << weight[i][2] << std::endl;
                }
            }
        }
    }
std::cout << std::endl;
}

//Function for printing the graph vartaxs. 
void Graph::print_graph(std::string s){
    int edges = vartexNum * (vartexNum -1);
    std::cout << "Your " << s << " graph is: " << std::endl;
    for(int j = 0; j < edges; j++){
        int x = this->weight[j][0];
        int y = this->weight[j][1];
        if(x != 0 && y != 0){
            std::cout << "(" << x << "," << y << ")" << std::endl;
        }
    }
std::cout << std::endl;
}

//Function that return the weight between vartax x and y in the graph.
int Graph::getWeight(int x, int y)const{
    int edges = vartexNum * (vartexNum -1);
    int w = 0;
    for(int i = 0; i < edges; i++){
        if((weight[i][0] == x && weight[i][1] == y) || (weight[i][0] == y && weight[i][1] == x)){
            w = weight[i][2];
        }
    }
    return w;
}

//Function that return the number of edges that the graph build from.
int Graph::getEdgeNum()const{
    int edgeNum = 0;
    int l = 0;
    while (weight[l][1] != 0){
        edgeNum++;
        l++;
    }
    return edgeNum;
}