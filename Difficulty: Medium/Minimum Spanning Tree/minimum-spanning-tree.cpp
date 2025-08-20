class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<bool> inMST(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        int sum = 0;
        pq.push({0, 0});
        sum += 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int weight = it.first;
            int node = it.second;
            
            if(inMST[node] != true){
                sum += weight;
                inMST[node] = true;
                for(auto &temp: adj[node]){
                    int v = temp.first;
                    int w = temp.second;
                    
                    pq.push({w, v});
                }  
            }
        }
        
        return sum;
        
    }
};