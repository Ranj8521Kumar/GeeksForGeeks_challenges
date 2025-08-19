class Solution {
  public:
    void BFS(vector<vector<int>> &adj, vector<int> &result, vector<int> &visited,  int u){
        queue<int> que;
        que.push(u);
        visited[u] =  true;
        
        while(!que.empty()){
            int u = que.front();
            que.pop();
            result.push_back(u);
            
            for(auto &v: adj[u]){
                if(!visited[v]){
                    que.push(v);
                    visited[v] = true;
                }
            }
        }
    }
  
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int v = adj.size();
        
        vector<int> result;
        vector<int> visited(v, false);
        
        BFS(adj, result, visited, 0);
        
        return result;
    }
};