/*You have a business with several offices; you want to lease phone lines to connect
them up with each other; and the phone company charges different amounts of money to
 connect different pairs of cities. You want a set of lines that connects all your
 offices with a minimum total cost. Solve the problem by suggesting appropriate
 data structures and using prim’s algorithm*/

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> primsalgo(vector<vector<pair<int, int>>> graph, vector<int> &visited, int startnode){
    int cost = 0;
    vector<pair<int, int>> mst;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, startnode, startnode});
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int charge = it[0];
        int node = it[1];
        int parent = it[2];
        if(visited[node]==1) continue;
        visited[node] = 1;
        mst.push_back({node, parent});
        cost += charge;
        for(auto it : graph[node]){
            int adjN = it.first;
            int edW = it.second;
            if(visited[adjN]!=1){
                pq.push({edW, adjN, node});
            }
        }
    }
    cout<<"Minimum Cost : "<<cost<<endl;
    return mst;
}
 
int main() {
    int V, E;
    cout << "Enter number of offices and lines: ";
    cin >> V >> E;
    vector<vector<pair<int, int>>> graph(V);
    cout << "Enter lines with charge: \n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    vector<int> visited(V, 0);
    int startnode = 0;
    vector<pair<int, int>> mst = primsalgo(graph, visited, startnode);
    cout<<"Minimum spanning tree lines: "<<endl;
    for(auto i : mst){
        if(i.first!=i.second)
            cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}
/*Enter number of offices and lines: 4 5
Enter lines with charge:
0 1 1
0 2 2
1 2 3
1 3 3
2 3 4
Minimum Cost : 7
Minimum spanning tree lines:
0 1
1 2
1 3
 Prim's algorithm is another greedy algorithm used to find the minimum spanning tree (MST) of a connected, undirected graph. Like Kruskal's algorithm, Prim's algorithm constructs an MST, but it does so by growing the tree from an arbitrary starting vertex rather than selecting edges. Prim's algorithm is particularly efficient for dense graphs or when the graph is represented using adjacency lists.

 Here's a step-by-step explanation of Prim's algorithm:

 1. **Initialization:**
    - Choose an arbitrary starting vertex as the initial vertex of the MST.
    - Initialize a priority queue (or min-heap) to store the vertices and their corresponding edge weights to the MST.
    - Initialize a list (or array) to keep track of which vertices have been included in the MST.

 2. **Selecting Edges:**
    - Begin with the chosen starting vertex.
    - For the current vertex, consider all its adjacent vertices that are not already in the MST.
    - Add these adjacent vertices to the priority queue along with the weight of the edge connecting them to the current vertex.

 3. **Growing the Tree:**
    - At each step, extract the vertex with the minimum edge weight from the priority queue.
    - If the extracted vertex has not already been included in the MST, add it to the MST.
    - Update the priority queue by adding all the adjacent vertices of the newly added vertex that are not already in the MST.
    - Repeat this process until all vertices are included in the MST.

 4. **Termination:**
    - The algorithm terminates when all vertices have been added to the MST.

 5. **Output:**
    - The list of edges obtained by adding the selected edges to the MST forms the minimum spanning tree.
    - Optionally, output the total weight of the MST, which is the sum of the weights of all the edges in the tree.

 Prim's algorithm operates efficiently with the help of a priority queue (or min-heap) data structure to efficiently select the next vertex to add to the MST based on the minimum edge weight. By growing the tree from an arbitrary starting vertex, Prim's algorithm ensures that the resulting MST is always connected and has the minimum possible total edge weight.*/
