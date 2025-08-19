class Solution {
  public:
    bool DFS(unordered_map<int, vector<int>> &adj, vector<int> &visited, int u, int parent){
        visited[u]= true;
        
        for(auto &v: adj[u]){
            if(!visited[v]){
                if(DFS(adj, visited, v, u)){
                    return true;
                }
            }else if(parent != v){
                    return true;
            }
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // create graph
        unordered_map<int, vector<int>> adj; 
        
        for(auto &edge: edges){
            int u = edge[0];
            int v =edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(V, false);
        for(int i = 0; i<V; i++){
            if(!visited[i] && DFS(adj, visited, i, -1)){
                return true;
            }
        }
        
        return false;
    }
};