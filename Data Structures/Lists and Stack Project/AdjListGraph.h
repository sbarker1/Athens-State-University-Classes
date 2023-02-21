//Samuel Barker
//00100768
//CS 372
//AdjListGraph.h file

//References:
//https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
//https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

#include "Graph.h"
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;

template <class N>
class AdjListGraph : public Graph<N> {
private:
    using Edges = list<pair<N, N>>;
    map<N, Edges > vertexMap;
public:
    // Default constuctor, create empty
    AdjListGraph() : Graph<N>() { };

    // Get the vertex map from the Graph we're copying
    AdjListGraph(const AdjListGraph& other) : Graph<N>()
    {
        vertexMap = other->vertexMap;
    }

    // Don't forget to overload the assignment operator
    AdjListGraph& operator= (const AdjListGraph& source)
    {
        vertexMap = source->vertexMap;
        return *this;
    }

    // Add the nodes in the list to graph
    AdjListGraph(vector<N> newNodes, vector<pair<N, N>> newEdges) :
        Graph<N>(newNodes, newEdges)
    {
        for (auto it = newNodes.begin();
            it < newNodes.end();
            ++it)
        {
            N node = *it;
            vertexMap[node].push_back(newEdges);
        }
    }

    //DFS Added.
    void Graph::DFS(int v)
    {
        // Mark the current node as visited and
        // print it
        visited[v] = true;
        cout << v << " ";

        // Recur for all the vertices adjacent
        // to this vertex
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                DFS(*i);
    }

    //BFS Added. 
    void Graph::BFS(int s)
    {
        // Mark all the vertices as not visited
        vector<bool> visited;
        visited.resize(V, false);

        // Create a queue for BFS
        list<int> queue;

        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.push_back(s);

        while (!queue.empty())
        {
            // Dequeue a vertex from queue and print it
            s = queue.front();
            cout << s << " ";
            queue.pop_front();

            // Get all adjacent vertices of the dequeued
            // vertex s. If a adjacent has not been visited,
            // then mark it visited and enqueue it
            for (auto adjecent : adj[s])
            {
                if (!visited[adjecent])
                {
                    visited[adjecent] = true;
                    queue.push_back(adjecent);
                }
            }
        }
    }

    // Clean up behind ourselves
    ~AdjListGraph() { }

    virtual bool adjacent(N x, N y) {
        Edges edges = vertexMap.at(x);
        pair<N, N>* searchEdge = new pair<N, N>(x, y);
        typename Edges::const_iterator begin = edges.begin();
        typename Edges::const_iterator end = edges.end();
        auto pos = std::find_if(begin, end,
            [&](pair<N, N> const& b) {
                bool match = (b.first == searchEdge->first
                    && b.second == searchEdge->second);
                return match;
            });
        bool match = false;
        if (pos != end) { match = true; }
        return (match);
    }

    virtual vector<N> neighbors(N x) {
        vector<N>* nodes = new vector<N>();
        Edges edges = vertexMap.at(x);
        for (typename Edges::const_iterator it = edges.begin(); it != edges.end(); it++) {
            pair<N, N> e = *it;
            nodes->push_back(e.first);
        }
        return *nodes;
    }

    virtual void addNode(N node) {
        Edges* newEdgeList = new Edges();
        vertexMap[node] = *newEdgeList;
    }

    virtual void addEdge(N x, N y) {
        pair<N, N> forwardEdge = make_pair(x, y);
        pair<N, N> backwardEdge = make_pair(y, x);
        Edges edgeList = vertexMap[x];
        edgeList.push_back(forwardEdge);
        vertexMap[y].push_back(backwardEdge);
    }

    virtual void deleteEdge(N x, N y) {
        pair<N, N> forwardEdge = make_pair(x, y);
        pair<N, N> backwardEdge = make_pair(y, x);
        vertexMap[x].remove(forwardEdge);
        vertexMap[y].remove(backwardEdge);
    }


};
