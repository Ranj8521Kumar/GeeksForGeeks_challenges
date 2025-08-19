class Solution {
  public:
    bool DFS(unordered_map<int, vector<int>>& adj, vector<int>& color, int currNode, int currColor){
        color[currNode] = currColor;
        
        for(auto &v: adj[currNode]){
            if(color[v] == -1){
                currColor = 1 - color[currNode];
                
                if(DFS(adj, color, v, currColor) == false){
                    return false;
                }
            }else{
                if(color[v] == color[currNode]){
                    return false;
                }
            }
        }
        
        return true;
    }
  
    bool isBipartite(int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(V, -1);
        // 0 -> Red
        // 1 -> Green
        
        for(int u = 0; u<V; u++){
            if(color[u] == -1 && DFS(adj, color, u, 0) == false){
                return false;
            }
        }
        
        return true;
    }
};