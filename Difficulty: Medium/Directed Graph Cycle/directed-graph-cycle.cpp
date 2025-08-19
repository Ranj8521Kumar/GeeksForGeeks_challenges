class Solution {
  public:
    bool DFS(unordered_map<int, vector<int>> &adj, vector<bool> &visited, vector<bool> &inRecurssion, int u){
        visited[u] = true;
        inRecurssion[u]= true;
        
        for(auto &v: adj[u]){
            if(!visited[v]){
                if(DFS(adj, visited, inRecurssion, v)){
                    return true;
                }
            }else{
                if(inRecurssion[v]){
                    return true;
                }
            }
        }
        
        inRecurssion[u] = false;
        return false;
    }
  
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V, false);
        vector<bool> inRecurssion(V, false);
        
        for(int u =  0; u<V; u++){
            if(!visited[u]  && DFS(adj, visited, inRecurssion, u)){
                return true;
            }
        }
        
       return false;
    }
};