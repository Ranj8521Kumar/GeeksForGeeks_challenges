//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function for BFS call
    void BFS(vector<vector<int>>& adj, vector<int>& indegree, queue<int>& que, vector<int>& result){
        while (!que.empty()) {
            int u = que.front();
            que.pop();

            result.push_back(u);

            for (auto &v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }
    }

    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<int> indegree(v, 0);

        // Calculate indegree of all vertices
        for (int u = 0; u < v; u++) {
            for (auto &node : adj[u]) {
                indegree[node]++;
            }
        }

        vector<int> result;
        vector<int> tempIndegree = indegree; // Copy of indegree to preserve original values

        queue<int> que;
        for(int u = 0; u<v; u++){
            if(indegree[u] == 0){
                que.push(u); // push all vetices of indegree Zero
            }
        }
        
        
        
        BFS(adj, tempIndegree, que, result);
        
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