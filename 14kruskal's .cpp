/*You have a business with several offices; you want to lease phone lines to connect
them up with each other; and the phone company charges different amounts of money
to connect different pairs of cities. You want a set of lines that connects all
your offices with a minimum total cost. Solve the problem by suggesting appropriate
data structures and using kruskal's algorithm*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }
    int findUpar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUpar(parent[node]);
    }
    void unionbyrank(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

vector<pair<int, pair<int, int>>> kruskal(vector<pair<int, pair<int, int>>>& edges, int V) {
    vector<pair<int, pair<int, int>>> mst;
    DisjointSet ds(V);
    sort(edges.begin(), edges.end()); // Sort edges by weight
    for(auto edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        int ulp_u = ds.findUpar(u);
        int ulp_v = ds.findUpar(v);
        if(ulp_u != ulp_v) {
            mst.push_back(edge);
            ds.unionbyrank(ulp_u, ulp_v);
        }
    }
    return mst;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<pair<int, pair<int, int>>> edges(E);
    cout << "Enter edges with weight: \n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, {u, v}};
    }
    vector<pair<int, pair<int, int>>> mst = kruskal(edges, V);
    int totalCost = 0;
    cout << "Minimum spanning tree : " << endl;
    for(auto edge : mst) {
        totalCost += edge.first;
        cout << edge.second.first << " " << edge.second.second << endl;
    }
    cout << "Minimum Cost : " << totalCost << endl;
    return 0;
}
/*Enter number of vertices and edges: 4 5
Enter edges with weight:
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
Minimum spanning tree :
2 3
0 3
0 1
Minimum Cost : 19
Here's a short algorithm for Kruskal's algorithm:

 Kruskal's algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a connected, undirected graph. The minimum spanning tree of a graph is a subset of its edges that form a tree connecting all the vertices together with the minimum possible total edge weight. Kruskal's algorithm achieves this by iteratively adding the edges with the smallest weights while avoiding the formation of cycles.

 Here's a step-by-step explanation of Kruskal's algorithm:

 1. **Initialization:**
    - Create an empty list to store the edges of the minimum spanning tree (MST).
    - Sort all the edges of the graph in non-decreasing order of their weights.

 2. **Iterate Over Sorted Edges:**
    - Start iterating over the sorted list of edges.
    - For each edge, check if adding it to the MST will create a cycle. This can be done by checking if the vertices at the two ends of the edge belong to the same connected component or not.

 3. **Add Edge to MST:**
    - If adding the edge does not create a cycle (i.e., the vertices at its two ends belong to different connected components), add the edge to the MST.
    - Union the two connected components of the vertices at the ends of the edge, effectively merging them into a single connected component.

 4. **Termination:**
    - Continue this process until all vertices are part of a single connected component or until all edges have been considered.

 5. **Output:**
    - The list of edges obtained at the end of the process forms the minimum spanning tree.
    - Optionally, output the total weight of the MST, which is the sum of the weights of all the edges in the tree.

 Kruskal's algorithm operates efficiently with the help of a data structure called the Disjoint Set Union (DSU) or Union-Find data structure. This data structure allows for efficient checking of whether adding an edge will create a cycle and for merging connected components. Overall, Kruskal's algorithm provides an optimal solution for finding the minimum cost set of edges that connects all vertices in a graph.*/
