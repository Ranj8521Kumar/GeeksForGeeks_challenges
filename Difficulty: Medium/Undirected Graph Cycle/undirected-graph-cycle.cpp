//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    //function for isCycleDFS
    bool isCycleDFS(vector<vector<int>>& adj, int u, vector<int>&visited, int parent){
        visited[u] = true;
        
        for(auto &v: adj[u]){
            if(visited[v] && v != parent){
                return true;
            }
            
            if(!visited[v]){
                if(isCycleDFS(adj, v, visited, u)){
                    return true;
                }
            }
        }
        
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();
        
        vector<int> visited(v, false);
        
        for(int u = 0; u<v; u++){ // for not connected graph
            if(!visited[u] && isCycleDFS(adj, u, visited, -1)){
                return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends