//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        int v = n;
        vector<vector<pair<int, int>>> adj(v+1);

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> distance(v+1, INT_MAX);
        distance[1] = 0;

        vector<int> parent(v+1, -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});

        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();

            for(auto &v: adj[u.second]){
                int node = v.first;
                int weight = v.second;

                int updatedDistance = u.first + weight;

                if(updatedDistance < distance[node]){
                    distance[node] = updatedDistance;
                    parent[node] =  u.second;
                    pq.push({updatedDistance, node});
                }
            }
        }

        if(distance[v] == INT_MAX){
            return  {-1};
        }

        vector<int> path;
        int current = v;

        while(current != -1){
            path.push_back(current);
            current = parent[current];
        }

        path.push_back(distance[v]);

        reverse(path.begin(), path.end());

        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends