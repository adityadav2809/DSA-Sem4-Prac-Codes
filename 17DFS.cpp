/*Represent a given graph using adjacency list representation to perform DFS traversal on graph.*/

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[], int node, vector<int> &visited, vector<int> &ans){
    visited[node] = 1;
    ans.push_back(node);
    for(auto it : adj[node]){
        if(visited[it]!=1){
            dfs(adj, it, visited, ans);
        }
    }
}

int main(){
    int V, E;
    cout<<"enter no. of edges and vertices: ";
    cin>>V>>E;
    vector<int> adj[V];
    cout<<"enter the edges: ";
    for(int i = 0; i<E; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> visited(V,0);
    vector<int> ans;
    int node = 0;
    dfs(adj, node, visited, ans);
    cout<<"DFS traversal : ";
    for(auto i : ans){
        cout<<i<<" ";
    }
}
/*Here's the algorithm for representing a graph using adjacency list representation and performing DFS traversal:
 
 1. **Include Necessary Libraries**: Include the required headers for input-output operations and data structures.

 2. **DFS Function**:
    - Define a function `dfs` that performs Depth-First Search traversal.
    - Parameters:
      - `vector<int> adj[]`: Adjacency list representation of the graph.
      - `int node`: Current node being visited.
      - `vector<int> &visited`: A vector to mark visited nodes.
      - `vector<int> &ans`: A vector to store the DFS traversal order.
    - Implementation:
      - Mark the current node as visited and add it to the answer vector.
      - Iterate through all adjacent nodes of the current node.
      - If an adjacent node is not visited, recursively call `dfs` on that node.

 3. **Main Function**:
    - Take input for the number of vertices and edges (`V` and `E`).
    - Create an adjacency list (`adj`) of size `V`.
    - Input the edges of the graph and construct the adjacency list.
    - Initialize a vector `visited` to mark visited nodes and a vector `ans` to store the DFS traversal order.
    - Start DFS traversal from a given starting node (e.g., node 0).
    - Output the DFS traversal order.

 4. **Output**:
    - Output the DFS traversal order obtained from the `ans` vector.

 5. **End**.

 This algorithm represents a graph using adjacency list representation and performs DFS traversal on it.*/
