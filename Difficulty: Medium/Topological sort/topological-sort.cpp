class Solution {
  public:
    void DFS(unordered_map<int, vector<int>>& adj, vector<bool>& visited, stack<int>& st, int u){
        visited[u] = true;
        
        for(auto &v: adj[u]){
            if(!visited[v]){
                DFS(adj, visited, st, v);
            }
        }
        
        st.push(u);
    }
  
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V, false);
        stack<int> st;
        for(int u = 0; u<V; u++){
            if(!visited[u]){
                DFS(adj, visited, st, u);
            }
        }
        
        vector<int> result;
        
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        
        return result;
    }
};