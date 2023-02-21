//Samuel Barker
//00100768
//CS 372
//AdjListGraph.h file

//References:
//https://www.geeksforgeeks.org/implementation-of-dfs-using-adjacency-matrix/
//https://www.geeksforgeeks.org/implementation-of-bfs-using-adjacency-matrix/

#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "Graph.h"
using namespace std;
template <class N>
class AdjMatrixGraph : public Graph<N> {
private:
    class NodeEntry {
    public:
        N node;
        int index;
    };
    const static int maxSize = 10;
    bool adjMatrix[maxSize][maxSize];
    NodeEntry* nodes[maxSize];
    int numNodes = 0;
    int findNodeInMatrix(N x) {
        for (int j = 0; j < numNodes; ++j)
        {
            if (x == nodes[j]->node)
            {
                return j;
            }
        }
        return -1;
    }
public:
    // Default constuctor, create empty
    AdjMatrixGraph()
    {
        for (int i = 0; i < maxSize; i++)
            for (int j = 0; j < maxSize; j++)
            {
                adjMatrix[i][j] = false;
            }
    }
    // Add the nodes in the list to graph
    AdjMatrixGraph(vector<N> newNodes, vector<pair<N, N>> newEdges)
    {
        adjMatrix = new NodeEntry[maxSize][maxSize];
        for (typename vector<N>::const_iterator it = newNodes.begin();
            it < newNodes.end();
            ++it)
        {
            NodeEntry ne = new NodeEntry();
            ne.node = *it;
            ne.index = numNodes;
            nodes[numNodes] = ne;
            adjMatrix[numNodes][numNodes] = true;
        }
        for (typename vector<pair<N, N>>::const_iterator it = newEdges.begin();
            it < newEdges.end();
            ++it)
        {
            pair<N, N> edge = *it;
            int sourceIndex = findNodeInMatrix(edge.first);
            int destIndex = findNodeInMatrix(edge.second);
            if (sourceIndex != -1)
            {
                if (destIndex != -1)
                {
                    adjMatrix[sourceIndex][destIndex] = true;
                }
            }
        }
    }

    //ADDED DFS FUNCTION
    void dfs(int start, vector<bool>& visited)
    {

        // Print the current node
        cout << start << " ";

        // Set current node as visited
        visited[start] = true;

        // For every node of the graph
        for (int i = 0; i < adj[start].size(); i++) {

            // If some node is adjacent to the current node
            // and it has not already been visited
            if (adj[start][i] == 1 && (!visited[i])) {
                dfs(i, visited);
            }
        }
    }

    //ADDED MATRIX BFS FUNCTION
    void bfs(int start)
    {
        // Visited vector to so that
        // a vertex is not visited more than once
        // Initializing the vector to false as no
        // vertex is visited at the beginning
        vector<bool> visited(adj.size(), false);
        vector<int> q;
        q.push_back(start);

        // Set source as visited
        visited[start] = true;

        int vis;
        while (!q.empty()) {
            vis = q[0];

            // Print the current node
            cout << vis << " ";
            q.erase(q.begin());

            // For every adjacent vertex to the current vertex
            for (int i = 0; i < adj[vis].size(); i++) {
                if (adj[vis][i] == 1 && (!visited[i])) {

                    // Push the adjacent node to the queue
                    q.push_back(i);

                    // Set
                    visited[i] = true;
                }
            }
        }
    }

    // Clean up behind ourselves
    ~AdjMatrixGraph() {};

    virtual bool adjacent(N x, N y)
    {
        bool result = false;
        int xIndex = findNodeInMatrix(x);
        int yIndex = findNodeInMatrix(y);
        if ((xIndex != -1) && (yIndex != -1))
        {
            bool xy = adjMatrix[xIndex][yIndex];
            bool yx = adjMatrix[yIndex][xIndex];
            result = xy && yx;
        }
        return(result);
    }

    virtual vector<N> neighbors(N x)
    {
        vector<N>* v = new vector<N>();
        int xIndex = findNodeInMatrix(x);
        if (xIndex != -1)
        {
            for (int i = 0; i < numNodes; ++i) {
                if (adjMatrix[xIndex][i] == true) {
                    v->push_back(nodes[i]->node);
                }
            }
        }
        return *v;
    }
    virtual void addNode(N node)
    {
        NodeEntry* ne = new NodeEntry();
        ne->node = node;
        ne->index = numNodes;
        nodes[numNodes] = ne;
        adjMatrix[numNodes][numNodes] = true;
        numNodes++;

    }
    virtual void addEdge(N x, N y) {
        int xIndex = findNodeInMatrix(x);
        int yIndex = findNodeInMatrix(y);
        if ((xIndex != -1) && (yIndex != -1))
        {
            adjMatrix[xIndex][yIndex] = true;
        }
    }
    virtual void deleteEdge(N x, N y)
    {
        int xIndex = findNodeInMatrix(x);
        int yIndex = findNodeInMatrix(y);
        adjMatrix[xIndex][yIndex] = false;
    }


};

