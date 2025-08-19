class Solution {
  public:
    void dfsTravesal(vector<vector<int>>& adj, vector<int> &result, vector<int> &visited, int u){
        if(visited[u] == true) return;
        
        result.push_back(u);
        visited[u] = true;
        
        for(auto &v: adj[u]){
            if(!visited[v]){
                dfsTravesal(adj, result, visited, v);
            }
            
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();
        vector<int> result;
        
        vector<int> visited(v, false);
        
        dfsTravesal(adj, result, visited, 0);
        
        return result;
        
    }
};