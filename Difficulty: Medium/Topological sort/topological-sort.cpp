//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    //function for dfs call
    void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited, stack<int>& st){
        visited[u] = true;
        
        for(auto &v: adj[u]){
            if(!visited[v]){
                DFS(adj, v, visited, st);
            }
        }
        
        st.push(u);
    }
    
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int v = adj.size();
        
        vector<bool> visited(v, false);
        vector<int> result;
        stack<int> st;
        
        for(int u = 0; u<v; u++){
            if(!visited[u]){
                DFS(adj, u, visited, st);
            }
        }
        
        while(!st.empty()){
            auto it = st.top();
            st.pop();
            
            result.push_back(it);
        }
        
        return result;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends