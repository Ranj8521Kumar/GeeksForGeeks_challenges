// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> result(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({src, 0});
        result[src] = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int node = it.first;
            int weight = it.second;
            
            for(auto &temp: adj[node]){
                int v = temp.first;
                int w = temp.second;
                
                if(w + weight < result[v]){
                    result[v] = (w + weight);
                    pq.push({v, (w+weight)});
                }
            }
        }
        
        return result;
    }
};