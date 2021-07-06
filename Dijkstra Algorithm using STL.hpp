#ifndef __DIJGKSTRA_STL_H
#define __DIJGKSTRA_STL_H

#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <limits>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> Pair;
const int INF = numeric_limits<int>::max();

class Dijkstra 
{
public:
    // Constructor
    Dijkstra(int V);

    // A function to add an edge to Graph
    void addEdge(int u, int v, int w);

    // Construct Shortest Path Distance 
    // "one source to all dest." version
    void shortestPath(int src);
private:
    // The number of vertcies.
	int V;
    vector<int> Dist;
	// In a weighted graph, we need to store vertex
	// and weight pair for every edge
    vector<list<Pair>> Graph;
};

Dijkstra::Dijkstra(int _V)
{
    V = _V;
    Graph.assign(V, list<Pair>());
}

void Dijkstra::addEdge(int u, int v, int w)
{   // If Graph is undirectd, Add only one.
	Graph[u].emplace_back(make_pair(v, w));
	Graph[v].emplace_back(make_pair(u, w));
}

void Dijkstra::shortestPath(int src)
{
    int a=0;
    cout << a++ << endl;
    Dist.assign(V, INF);
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    vector<bool> chk(V, false);
    pq.emplace(make_pair(0, src));
    Dist[src] = 0;

    while(!pq.empty())
    {
        cout << a++ << endl;
        int u = pq.top().second;
        pq.pop();
        chk[u] = true;

        for(auto& x: Graph[u])
        {
            int v = x.first;
            int w = x.second;
            
            if(!chk[v] && Dist[v] > Dist[u] + w)
            {
                Dist[v] = Dist[u] + w;
                pq.emplace(make_pair(Dist[v], v));
            }
        }

    }

	// Print shortest distances stored in dist[]
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, Dist[i]);
}

#endif