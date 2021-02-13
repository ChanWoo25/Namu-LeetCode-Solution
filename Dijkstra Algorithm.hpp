#ifndef __DIJGKSTRA_H
#define __DIJGKSTRA_H

#include <limits>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

class dijkstra{
#define INF std::numeric_limits<int>::max()
private:
    vector<vi> Graph;
    vi Dist;
    vector<bool> sptSet; // Shortest Path Tree SET
    int V; // The number of vertices

    int minDistVertex()
    {
        int _min = INF, _min_idx;
        for(unsigned v=0; v < V; v++)
            if(!sptSet[v] && Dist[v] <= _min)
                _min = Dist[v], _min_idx = v;
        return _min_idx;    
    }

    void update(unsigned u)
    {
        for(unsigned v = 0; v < V; v++)
        {
            if(!sptSet[v] && Graph[u][v] && Dist[u] != INF
                          && Dist[u] + Graph[u][v] < Dist[v])
                Dist[v] = Dist[u] + Graph[u][v];
        }
    }

    void constructShortestPathTree(int src)
    {
        for(unsigned cnt = 0; cnt < V-1; cnt++)
        {
            int u = minDistVertex();
            sptSet[u] = true;
            update(u);
        }
    }

    // A utility function to print the constructed distance array 
    void print() 
    { 
        printf("Vertex \t\t Distance from Source\n"); 
        for (int i = 0; i < V; i++) 
            printf("Vertex %d: %4d\n", i, Dist[i]); 
    } 

public:
    dijkstra(vector<vi> graph, int source)
    {
        V = graph.size();
        Dist.assign(V, numeric_limits<int>::max());
        sptSet.assign(V, false);
        Graph = graph;
        Dist[source] = 0;

        constructShortestPathTree(source);
    }

    int distance(int dest){
        if(Dist.empty()){
            cout << "Construct Shortest Path Tree first.\n";
            return -1;
        }
        return Dist[dest];
    }
};

#endif