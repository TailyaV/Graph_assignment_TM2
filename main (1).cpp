//taliyarial1@gmail.com
#include <iostream>
#include "Graph.hpp"
#include "Algorithms.hpp"
#include "LinkedList.hpp"
#include <stdio.h>

using namespace graph;

int main(){
    Graph g(4);
    g.addEdge(1,2);
    g.addEdge(1,3,8);
    g.addEdge(3,4,20);
    g.addEdge(3,2,20);
    g.addEdge(1,4,3);
    Algorithms a;
    Graph res = a.bfs(g,1);
    res.print_graph("BFS");
    Graph res2 = a.dfs(g,1);
    res2.print_graph("DFS");
    Graph res3 = a.dijkstra(g,3);
    res3.print_graph_weight("dijkstra");
    Graph mst1 = a.prim(g);
    mst1.print_graph_weight("prim");
    Graph mst = a.kroskal(g);
    mst.print_graph_weight("kroskal");
};