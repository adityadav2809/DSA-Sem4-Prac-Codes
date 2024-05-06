/*Represent a given graph using adjacency list representation to perform BFS traversal on graph.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int> adj[], int V, int node){
    vector<int> visited(V, 0);
    vector<int> ans;
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while(!q.empty()){
        int curr = q.front();
        ans.push_back(curr);
        q.pop();
        for(auto i : adj[curr]){
            if(visited[i]!=1){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    return ans;
}

int main() {
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
    int node = 0;
    vector<int> ans = bfs(adj, V, node);
    cout<<"BFS traversal : ";
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}
/*Here's the algorithm for representing a graph using adjacency list representation and performing BFS traversal:
 
 1. **Include Necessary Libraries**: Include the required headers for input-output operations and data structures.

 2. **BFS Function**:
    - Define a function `bfs` that performs Breadth-First Search traversal.
    - Parameters:
      - `vector<int> adj[]`: Adjacency list representation of the graph.
      - `int V`: Number of vertices in the graph.
      - `int node`: Starting node for BFS traversal.
    - Implementation:
      - Create a vector `visited` of size `V` to mark visited nodes.
      - Create a vector `ans` to store the BFS traversal order.
      - Create a queue `q` to perform BFS traversal.
      - Push the starting node `node` into the queue and mark it as visited.
      - While the queue is not empty:
        - Extract the front element `curr` from the queue.
        - Add `curr` to the answer vector.
        - Iterate through all adjacent nodes of `curr`.
        - If an adjacent node is not visited, push it into the queue and mark it as visited.
      - Return the answer vector containing the BFS traversal order.

 3. **Main Function**:
    - Take input for the number of vertices and edges (`V` and `E`).
    - Create an adjacency list (`adj`) of size `V`.
    - Input the edges of the graph and construct the adjacency list.
    - Call the `bfs` function with the adjacency list, number of vertices, and starting node.
    - Output the BFS traversal order obtained from the returned vector.

 4. **Output**:
    - Output the BFS traversal order obtained from the vector returned by the `bfs` function.

 5. **End**.

 This algorithm represents a graph using adjacency list representation and performs BFS traversal on it.*/
