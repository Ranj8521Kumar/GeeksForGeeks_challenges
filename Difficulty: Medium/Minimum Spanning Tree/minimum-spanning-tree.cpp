//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    typedef pair<int, pair<int, int>> p;
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[]) {
        // code here
        vector<bool> visited(v, false);
        vector<int> parent(v, -1);
        
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, {0, -1}}); //{wt, {node, from}}
        
        int result = 0;
        
        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();
            
            int includedNodeWithMST = u.second.first;
            int from = u.second.second;
            int wt = u.first;
            
            if(visited[includedNodeWithMST]) continue; //already include in MSt
            
            visited[includedNodeWithMST] = true;
            parent[includedNodeWithMST] = from;
            result += wt;
            
            for(auto &v: adj[includedNodeWithMST]){
                int node = v[0];
                int wt = v[1];
                
                if(!visited[node]){
                    pq.push({wt, {node, includedNodeWithMST}});
                }
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends