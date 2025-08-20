class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> result(n+1, INT_MAX);
        vector<int> parent(n+1, 0);
        
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 1});
        result[1] = 0;
        parent[1] = 1;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int weight = it.first;
            int node = it.second;
            
            for(auto &temp: adj[node]){
                int v = temp.first;
                int w = temp.second;
                
                if(w + weight < result[v]){
                    result[v] = (w + weight);
                    parent[v] = node;
                    pq.push({(w+weight), v});
                }
            }
        }
        
        if(result[n] == INT_MAX){
            return {-1};
        }
        
        vector<int> path;
        int node = n;
        
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        
        path.push_back(node);
        
        reverse(path.begin(), path.end());
        
        path.insert(path.begin(), result[n]);
        
        return path;
    }
};