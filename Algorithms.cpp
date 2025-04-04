//taliyarial1@gmail.com
#include <iostream>
#include "Algorithms.hpp"
#include "Graph.hpp"
#include "LinkedList.hpp"
#include <stdexcept>
#include <limits>

using namespace graph;

//Function of BFS algorithm on grapg g starting with vartax i. 
//The output is vartax order of BFS.
void Algorithms::bfs(const Graph& g, int i){
    if(g.getVartexNum() < i || i < 0){
        throw std::invalid_argument("The start vartex is not exist");
    }
    std::cout << "The BFS order is: " << std::endl;
    int x = g.getVartexNum();
    bool visited[x];
    for(int i = 0; i < x; i++){
        visited[i] = false;
    }
    LinkedList queue;
    Node* n = new Node(i);
    queue.addNode(n);
    visited[i-1] = true;
    int** vartaxArr = g.getNeighbors();
    while (!queue.isEmpty())
    {
        Node* curr = queue.removeLastNode();
        std::cout << curr->getValue() << " ";
        for(int j = 0; j < x -1; j++){
            if(vartaxArr[curr->getValue() -1][j] > 0 && visited[vartaxArr[curr->getValue() - 1][j] - 1] == false){
                Node* newN = new Node(vartaxArr[curr->getValue()-1][j]);
                queue.addNode(newN);
                visited[vartaxArr[curr->getValue()-1][j] - 1] = true;
            }
        }
        delete curr;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void Algorithms::dfs(const Graph& g, int i){
    if(g.getVartexNum() < i || i < 0){
        throw std::invalid_argument("The start vartex is not exist");
    }
    std::cout << "The DFS order is: " << std::endl;
    int x = g.getVartexNum();
    bool visited[x];
    for(int i = 0; i < x; i++){
        visited[i] = false;
    }
    LinkedList stack;
    Node* n = new Node(i);
    stack.addNode(n);
    visited[i-1] = true;
    int** vartaxArr = g.getNeighbors();
    while (!stack.isEmpty())
    {
        Node* curr = stack.removeFirstNode();
        std::cout << curr->getValue() << " ";
        for(int j = 0; j < x -1; j++){
            if(vartaxArr[curr->getValue() -1][j] > 0 && visited[vartaxArr[curr->getValue() - 1][j] - 1] == false){
                Node* newN = new Node(vartaxArr[curr->getValue()-1][j]);
                stack.addNode(newN);
                visited[vartaxArr[curr->getValue()-1][j] - 1] = true;
            }
        }
        delete curr; 
    }
    std::cout << std::endl;
    std::cout << std::endl;
}


//Function of dijkstra algorithm on grapg g starting with vartax i. 
//The output is the weight of the shortest paths between evry tow vartaxs in g.
void Algorithms::dijkstra(const Graph& g, int i){
    int** temp = g.getWeightArr();
    int edges = g.getEdgeNum();
    if(g.getVartexNum() < i || i < 0){
        throw std::invalid_argument("The start vartex is not exist");
    }
    for(int f = 0; f <  edges; f++){
        if(temp[f][2] < 0){
            throw std::invalid_argument("Negetive weight in dijkstra is invalid!");
        }
    }
    std::cout << "Dijkstra start vartax is: " << i << std::endl;
    int x = g.getVartexNum();
    int vartaxDist[x];
    for(int j = 0; j < x; j++){
        vartaxDist[j] = INF;
    }
    vartaxDist[i - 1] = 0;
    bool visited[x];
    for(int i = 0; i < x; i++){
        visited[i] = false;
    }
    LinkedList queue;
    Node* n = new Node(i, vartaxDist[i - 1]);
    queue.addNode(n);
    int** neighborsArr = g.getNeighbors();
    while (!queue.isEmpty()){
        Node* curr = queue.removePriority();
        visited[curr->getValue() - 1] = true;
        for(int k = 0; k < x - 1; k++){
            int currNeighbor = neighborsArr[curr->getValue() - 1][k];
            if(currNeighbor > 0 && visited[currNeighbor - 1] == false){
                int newWeight = curr->getDest() + g.getWeight(currNeighbor, curr->getValue());
                if(newWeight < vartaxDist[currNeighbor - 1] ){
                    vartaxDist[currNeighbor - 1] = newWeight;
                    Node* nNode = new Node(currNeighbor, vartaxDist[currNeighbor - 1]);
                    queue.addNode(nNode);
                }
            }
        }
        delete curr;
    }
    for(int r = 0; r < x; r++){
    std::cout <<"sorteth dist to " << r + 1 << " is " << vartaxDist[r] << std::endl;
    }
    std::cout << std::endl;
}


//Function of prim algorithm on grapg g. 
//The output is the minimal spanning tree of g.
Graph Algorithms::prim(const Graph& g){
    int** neigh = g.getNeighbors();
    int graphSize = g.getVartexNum();
    for(int i = 0;i < graphSize; i++){
        int flag = 0;
        for(int j = 0;j < graphSize - 1; j++){
            if(neigh[i][j] > 0){
                flag = 1;
            }
        }
        if(flag == 0){
            throw std::invalid_argument("Not connected graph, cant calculate MST");
        }
    }
    bool visited[graphSize];
    for(int i = 0; i < graphSize; i++){
        visited[i] = false;
    }
    std::cout << "Prim start vartax is: " << graphSize << std::endl;
    visited[graphSize - 1] = true;
    Graph mst(graphSize); //
    LinkedList queue;
    Algorithms::insertEdges(g, queue, graphSize);
    int** temp = g.getWeightArr();
    while (!queue.isEmpty()){
        Node* curr = queue.removePriority();
        int index = curr->getValue();
        if(visited[temp[index][0] - 1] == false){
            visited[temp[index][0] - 1] = true;
            mst.addEdge(temp[index][0], temp[index][1], temp[index][2]);
            Algorithms::insertEdges(g, queue, temp[index][0]);
        }
        else if(visited[temp[index][1] - 1] == false){
            visited[temp[index][1] - 1] = true;
            mst.addEdge(temp[index][0], temp[index][1], temp[index][2]);
            Algorithms::insertEdges(g, queue, temp[index][1]);
        }
        delete curr;
    }
    return mst;
}

//This function insert to the queue all the neighbors of vartax var in graph g.
void Algorithms::insertEdges(const Graph& g, LinkedList& queue, int var){
    int** temp = g.getWeightArr();
    int edges = g.getVartexNum() * (g.getVartexNum() -1);
    for(int f = 0; f <  edges; f++){
        if(temp[f][0] == 0 && temp[f][1] == 0){
            break;
        }
        if(temp[f][0] == var){
            Node* n = new Node( f,temp[f][2]);
            queue.addNode(n);
        }
        else if(temp[f][1] == var){
            Node* n = new Node( f,temp[f][2]);
            queue.addNode(n);
        }
    }
}

//Function of kroskal algorithm on grapg g. 
//The output is the minimal spanning tree of g.
Graph Algorithms::kroskal(const Graph& g){
    std::cout << "Started Kruskal Algorithm, the MST is: " << std::endl;
    int** neigh = g.getNeighbors();
    int graphSize = g.getVartexNum();
    for(int i = 0;i < graphSize; i++){
        int flag = 0;
        for(int j = 0;j < graphSize - 1; j++){
            if(neigh[i][j] > 0){
                flag = 1;
            }
        }
        if(flag == 0){
            throw std::invalid_argument("Not connected graph, cant calculate MST");
        }
    }
    int** sortEdges = Algorithms::sort(g);
    int edgeNum = g.getEdgeNum();
    int x = g.getVartexNum();
    int mst[x];
    for(int i = 0; i < x; i++){
        mst[i] = 0;
    }
    Graph mstGraph(x);
    for(int i = 0; i < edgeNum; i++){
        int u = sortEdges[i][0];
        int w = sortEdges[i][1];
        if(!(find(mst, x, u) && find(mst, x, w))){
            mstGraph.addEdge(u, w, sortEdges[i][2]);
            int k = 0;
            if(!find(mst, x, u)){
                while (mst[k] != 0){
                    k++;
                }
                if(k < x){
                    mst[k] = u;
                }
            }
            int p = 0;
            if(!find(mst, x, w)){
                while (mst[p] != 0){
                    p++;
                }
                if(p < x){
                    mst[p] = w;
                }
            }
        }
    }
    return mstGraph;
}

//This function sort all the edges by their weights with bubble sort. 
int** Algorithms::sort(const Graph& g){
    int** edges = g.getWeightArr();
    int edgeNum = g.getEdgeNum();
    for(int i = 0; i < edgeNum; i++){
        for(int j = 0; j < edgeNum - i - 1; j++){
            if(edges[j][2] > edges[j + 1][2]){
                for(int k = 0; k < 3; k++){
                    int temp = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp;
                }
            }
        }
    }
    return edges;
}

//This function used for find from 'union-find'- to check the bellonging of vartax var.
bool Algorithms::find(int arr[], int arrSize, int var){
    for(int i = 0; i < arrSize; i++){
        if(arr[i] == var){
            return true;
        }
    }
    return false;
}


