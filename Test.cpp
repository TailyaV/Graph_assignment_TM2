//taliyarial1@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "Algorithms.hpp"
#include "Graph.hpp"
#include "doctest.h"

//Class BeforeEach is for building a function that will happend befor each test.
class BeforeEach {
public:
    Graph g;
    Algorithms a;

    BeforeEach():g(4) {
        g.addEdge(1, 2);
        g.addEdge(2, 3, 1);
        g.addEdge(1, 3, 8);
    }
};

TEST_CASE_FIXTURE(BeforeEach, "test addEdge") {
    int** temp = g.getWeightArr();
    int** neighbors = g.getNeighbors();
    CHECK(temp[0][2] == 1);
    CHECK(temp[1][1] == 3);
    CHECK(temp[2][2] == 8);
    CHECK(neighbors[0][0] == 2);
    CHECK(neighbors[1][1] == 3);
    CHECK_THROWS_AS_MESSAGE(g.addEdge(6,4,7);, std::invalid_argument, "unexisted vartex");

}

TEST_CASE_FIXTURE(BeforeEach, "test removeEdge") {
    int** neighbors = g.getNeighbors();  
    g.removeEdge(2, 3);
    CHECK(neighbors[1][2] == 0);
    CHECK_THROWS_AS_MESSAGE(g.removeEdge(2,3), std::invalid_argument, "invalide argument, edge dosent exist");
}

TEST_CASE_FIXTURE(BeforeEach, "test getEdgeNum") {
    int x = g.getEdgeNum();
    CHECK(x == 3);
}

TEST_CASE_FIXTURE(BeforeEach, "test bfs") {
    CHECK_THROWS_AS_MESSAGE(a.bfs(g, 6), std::invalid_argument, "The start vartex is not exist");
}

TEST_CASE_FIXTURE(BeforeEach, "test dfs") {
    CHECK_THROWS_AS_MESSAGE(a.dfs(g, -2), std::invalid_argument, "The start vartex is not exist");
}

TEST_CASE_FIXTURE(BeforeEach, "test dijkstra") {
    CHECK_THROWS_AS_MESSAGE(a.dijkstra(g, 8), std::invalid_argument, "The start vartex is not exist");
    g.addEdge(2,4,-5);
    CHECK_THROWS_AS_MESSAGE(a.dijkstra(g, 6), std::invalid_argument, "Negetive weight in dijkstra is invalid!");
}

TEST_CASE_FIXTURE(BeforeEach, "test prim") {
    CHECK_THROWS_AS_MESSAGE(a.prim(g), std::invalid_argument, "Not connected graph, cant calculate MST");
    g.addEdge(2,4,5);
    Graph temp = a.prim(g);
    int edgeNum = temp.getEdgeNum();
    int** neigh = temp.getNeighbors();
    CHECK_EQ(edgeNum, 3);
    CHECK(neigh[0][0] == 2);
}

TEST_CASE_FIXTURE(BeforeEach, "test kroskal") {
    CHECK_THROWS_AS_MESSAGE(a.kroskal(g), std::invalid_argument, "Not connected graph, cant calculate MST");
    g.addEdge(2,4,5);
    Graph temp = a.kroskal(g);
    int edgeNum = temp.getEdgeNum();
    int** neigh = temp.getNeighbors();
    CHECK_EQ(edgeNum, 3);
    CHECK(neigh[0][0] == 2);
}