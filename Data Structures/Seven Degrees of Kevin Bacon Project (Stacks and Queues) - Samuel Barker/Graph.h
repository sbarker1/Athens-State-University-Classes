#pragma once
#include <iostream>
#include <vector>
#include "Matrix.h"

using namespace std;

class Graph
{
public:
    Graph(int numVertices);

    bool hasEdge(int v, int w);

    void addEdge(int v, int w, int edge);

    int getEdge(int v, int w);

    void BFS(int s, vector<int>& distance, vector<int>& go_through);

private:
    Matrix<int> adj; 


};



