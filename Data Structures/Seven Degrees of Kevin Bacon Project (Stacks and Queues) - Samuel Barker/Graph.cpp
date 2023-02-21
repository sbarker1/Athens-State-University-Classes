#include <cassert>
#include "Graph.h"
#include <queue>


Graph::Graph(int numVertices) :adj(Matrix<int>(numVertices, numVertices, 0))
{
}

bool Graph::hasEdge(int v, int w)
{
    assert(v >= 0 && v < adj.GetSizeX() && w >= 0 && w < adj.GetSizeX());
    if (adj(v, w) == 0)
        return false;
    return true;
}

void Graph::addEdge(int v, int w, int edge)
{
    assert(v >= 0 && v < adj.GetSizeX() && w >= 0 && w < adj.GetSizeX());
    adj(v, w) = edge;
    adj(w, v) = edge;
}

int Graph::getEdge(int v, int w)
{
    assert(v >= 0 && v < adj.GetSizeX() && w >= 0 && w < adj.GetSizeX());
    return adj(v, w);
}

void Graph::BFS(int s, vector<int>& distance, vector<int>& go_through)
{
    vector<int> visited(distance.size());
    for (int i = 0; i < distance.size(); i++)
        visited[i] = false;
    visited[s] = true;
    distance[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int start = q.front();
        q.pop();
        for (int i = 0; i < distance.size(); i++) {
            if (hasEdge(start, i) == true) {
                if (visited[i] == false) {
                    visited[i] = true;

                    distance[i] = distance[start] + 1;
                    go_through[i] = start;
                    q.push(i);
                }
            }
        }
    }

}