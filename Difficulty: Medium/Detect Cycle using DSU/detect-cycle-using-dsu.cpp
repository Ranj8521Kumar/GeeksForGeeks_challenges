class Solution {
  public:
    int find(int u, vector<int> &parent){
        if(u == parent[u]){
            return u;
        }
        
        return parent[u] = find(parent[u], parent);
    }
    
    
    void Union(int u, int v, vector<int> &parent){
        parent[u] = v;
    }
  
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> parent(V, 0);
        for(int i = 0; i<V; i++){
            parent[i] = i;
        }
        
        for(int u = 0; u<V; u++){
            for(auto &v: adj[u]){
                if(u < v){
                    int parentU = find(u, parent);
                    int parentV = find(v, parent);
                    
                    if(parentU == parentV) return true;
                    
                    Union(parentU, parentV, parent);
                }
            }
        }
        
        return 0;
    }
};