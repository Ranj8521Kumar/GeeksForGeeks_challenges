//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        
        //using khan's algorithm or using bfs or using topological sort
        
        int v = adj.size();
        
        vector<int> indegree(v, 0);
        
        for(int u = 0; u<v; u++){
            for(auto &v: adj[u]){
                indegree[v]++;
            }
        }
        
        queue<int> que;
        for(int u = 0; u<v; u++){
            if(indegree[u] == 0){
                que.push(u);
            }
        }
        
        int count = 0;
        
        while(!que.empty()){
            int u = que.front();
            que.pop();
            
            count++;
            
            for(auto &v: adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    que.push(v);
                }
            }
        }
        
        if(count !=  v){
            return true;
        }
        
        return false;
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
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends