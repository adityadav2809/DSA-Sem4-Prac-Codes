/*Write a c++ program for below problem statement 
Tour operator organizes guided bus trips across the Maharashtra. Tourists may 
have different preferences. Tour operator offers a choice from many different 
routes. Every day the bus moves from starting city S to another city F as chosen 
by client. On this way, the tourists can see the sights alongside the route 
travelled from S to F. Client may have preference to choose route. There is a 
restriction on the routes that the tourists may choose from, the bus has to take 
a short route from S to F or a route having one distance unit longer than the 
minimal distance. Two routes from S to F are considered different if there is at 
least one road from a city A to a city B which is part of one route, but not of 
the other route.*/

#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& graph, int start, vector<int>& distance) {
    distance[start] = 0;
    set<pair<int,int>> s;
    s.insert({0, start});
    while (!s.empty()) {
        auto it = *(s.begin());
        int u = it.second;
        int d = it.first;
        s.erase(s.begin());
        for (auto it : graph[u]) {
            int v = it.first;
            int dis = it.second;
            if (d + dis < distance[v]) {
                if (distance[v] != INT_MAX) {
                    s.erase({distance[v], v});
                }
                distance[v] = d + dis;
                s.insert({distance[v], v});
            }
        }
    }
}

int main() {
    int V, E; 
    cout << "Enter number of cities and roads: ";
    cin >> V >> E;
    vector<vector<pair<int, int>>> graph(V);
    cout << "Enter roads and distances: \n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});  
        graph[v].push_back({u, w});
    }
    int source, destination;
    cout << "Enter starting city and destination city: ";
    cin >> source >> destination;
    vector<int> distance(V, INT_MAX);
    dijkstra(graph, source, distance);
    if (distance[destination] != INT_MAX) {
        cout << "Shortest distance from city " << source << " to city " << destination << ": " << distance[destination] << endl;
    } else {
        cout << "No path found from city " << source << " to city " << destination << endl;
    }
    return 0;
}
/*
Enter number of cities and roads: 4 5
Enter roads and distances:
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
Enter starting city and destination city: 0
2
Shortest distance from city 0 to city 2: 6


=== Code Execution Successful ===
 Dijkstra's algorithm is a popular algorithm used to find the shortest path from a source vertex to all other vertices in a weighted graph. Here's how it works:

 1. **Initialization**: Initialize the distance to all vertices from the source vertex as infinity, except for the source itself, which is set to zero. Also, maintain a set of vertices whose shortest distance from the source is already finalized.

 2. **Select the minimum distance vertex**: From the set of vertices not yet processed, pick the vertex with the minimum distance value and mark it as processed.

 3. **Update distances**: For the selected vertex, consider all of its adjacent vertices and calculate their tentative distances through the current vertex. Compare these newly calculated tentative distances with the current known shortest distance for each vertex. If the newly calculated tentative distance is less than the current known distance, update the distance.

 4. **Repeat**: Repeat steps 2 and 3 until all vertices are processed.

 Dijkstra's algorithm is typically implemented using a priority queue or a set to efficiently select the vertex with the minimum distance.

 Here's a high-level overview of the algorithm in pseudocode:

 ```
 function Dijkstra(Graph, source):
     dist[] is an array of distances initialized to infinity for all vertices
     Mark source distance as 0
     Create a priority queue Q
     Add source to Q
     while Q is not empty:
         u ← vertex in Q with minimum distance
         Remove u from Q
         for each neighbor v of u:
             alt ← dist[u] + length(u, v)
             if alt < dist[v]:
                 dist[v] ← alt
                 Add v to Q
     return dist[]
 ```

 Dijkstra's algorithm guarantees the shortest path in a graph with non-negative edge weights. It's commonly used in various applications like network routing protocols, GPS systems, and traffic planning.*/
