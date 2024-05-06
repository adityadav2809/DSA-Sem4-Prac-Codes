/*Write a c++  program to perform topological sort on a graph.*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int node, stack<int> &st, vector<int> &visited){
    visited[node] = 1;
    for(auto it : adj[node]){
        if(visited[it]!=1){
            dfs(adj, it, st, visited);
        }
    }
    st.push(node);
}

int main() {
    int V,E;
    cout<<"Enter No. of Vertices and edges : ";
    cin>>V>>E;
    vector<int> adj[V];
    cout << "Enter the edges (source destination):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    stack<int> ans;
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if(!visited[i]){
            dfs(adj, i, ans, visited);
        }
    }
    cout << "Topological Sort Order: ";
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    return 0;
}
/*Here's the algorithm for the Topological Sort program:

1. **Include necessary header files**:
   - Include `<bits/stdc++.h>` to utilize standard C++ libraries.

2. **Define a function for depth-first search (DFS)**:
   - Create a function named `dfs` that performs a depth-first search traversal on the graph.
   - It takes parameters:
     - `adj[]`: Adjacency list representing the graph.
     - `node`: Current node being visited.
     - `st`: Stack to store the topological order.
     - `visited`: Vector to track visited nodes.
   - Inside the function:
     - Mark the current node as visited.
     - Recursively call `dfs` for unvisited adjacent nodes.
     - Push the current node onto the stack after visiting all its adjacent nodes.

3. **Define the main function**:
   - Create a `main` function.
   - Declare variables `V` and `E` to store the number of vertices and edges respectively.
   - Input the number of vertices and edges from the user.
   - Create an adjacency list `adj[]` to represent the graph.
   - Input the edges of the graph from the user and populate the adjacency list accordingly.
   - Initialize an empty stack `ans` to store the topological order.
   - Initialize a vector `visited` to track visited nodes, initially all set to 0.
   - Iterate through each vertex and perform DFS if not visited yet, passing the adjacency list, current node, stack, and visited vector.
   - Print the topological sort order by popping elements from the stack and printing them.

4. **End**.

This algorithm outlines the steps to perform topological sort on a directed acyclic graph (DAG) using DFS.*/
