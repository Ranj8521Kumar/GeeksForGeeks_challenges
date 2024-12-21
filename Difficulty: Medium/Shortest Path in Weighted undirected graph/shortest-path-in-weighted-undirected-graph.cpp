//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Create adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        // Distance array and priority queue
        vector<int> distance(n + 1, INT_MAX);
        vector<int> parent(n + 1, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Start from node 1
        distance[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            pair<int, int> u = pq.top(); // Extract top element
            pq.pop();
            int currentDistance = u.first;
            int currentNode = u.second;

            for (const auto& neighbor : adj[currentNode]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                int newDist = currentDistance + weight;

                if (newDist < distance[nextNode]) {
                    distance[nextNode] = newDist;
                    parent[nextNode] = currentNode;
                    pq.push({newDist, nextNode});
                }
            }
        }

        // If no path exists to node n
        if (distance[n] == INT_MAX) {
            return {-1};
        }

        // Reconstruct the shortest path
        vector<int> path;
        int current = n;
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        
        path.push_back(distance[n]);
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