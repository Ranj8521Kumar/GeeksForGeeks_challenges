//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //function for find
    int find(int u, vector<int>& parent){
        if(u == parent[u]){
            return u;
        }
        
        return find(parent[u], parent);
    }
    
    void unionSet(int u,  int v, vector<int>& parent){
        int parent_u = find(u, parent);
        int parent_v = find(v, parent);
        
        if(parent_u !=  parent_v){
            parent[parent_u] = parent_v;
        }
    }
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int v, vector<int>adj[])
	{
	    // Code here
	    vector<int> parent(v);
	    
	    for(int u = 0; u<v; u++){
	        parent[u] = u;
	    }
	    
	    for(int u = 0; u<v; u++){
	        for(auto &v: adj[u]){
	            if(u<v){
	                int parent_u = find(u, parent);
	                int parent_v = find(v, parent);
	                
	                if(parent_u == parent_v){
	                    return true;
	                }
	                
	                unionSet(u, v, parent);
	            }
	        }
	    }
	    
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends