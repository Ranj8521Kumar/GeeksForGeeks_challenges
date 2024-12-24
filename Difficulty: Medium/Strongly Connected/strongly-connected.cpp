//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Position this line where user code will be pasted.
class Solution {
  public:
    void DFSForTopoSort(vector<vector<int>>& adj, int u, vector<int>&
    visited, stack<int>& st){
        visited[u] = true;
        
        for(auto &v: adj[u]){
            if(!visited[v]){
                visited[v] = true;
                DFSForTopoSort(adj, v, visited, st);
            }
        }
        
        st.push(u);
    }
  
    void topologicalSort(vector<vector<int>>& adj, stack<int>& st){
        int v = adj.size();
        vector<int> visited(v, false);
        
        for(int u = 0; u<v; u++){
            if(!visited[u]){
                DFSForTopoSort(adj, u, visited, st);
            }
        }
    }
  
    void DFS(vector<vector<int>>& adj, int u, vector<int>& visited){
        visited[u] = true;
        
        for(auto &v: adj[u]){
            if(!visited[v]){
                visited[v] = true;
                DFS(adj, v, visited);
            }
        }
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int v = adj.size();
        
        //for topological sort
        stack<int> st;
        topologicalSort(adj, st);
        
        //reverse the edge of original graph and make a reversedGraph
        vector<vector<int>> reversedGraph(v);
        for(int i = 0; i<v; i++){
            for(auto &node: adj[i]){
                reversedGraph[node].push_back(i);
            }
        }
        
        //visited array for dfs calls
        vector<int> visited(v, false);
        
        int count = 0;
        
        //call dfs on order to topological sort stored in the stack
        while(!st.empty()){
            int u = st.top();
            st.pop();
            
            if(!visited[u]){
                DFS(reversedGraph, u, visited);
                count++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends