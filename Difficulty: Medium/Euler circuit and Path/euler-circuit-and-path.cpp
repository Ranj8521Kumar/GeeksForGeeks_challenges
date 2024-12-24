//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void DFS(vector<int>adj[], int u, vector<int>& visited){
        visited[u] = true;
        
        for(auto &v: adj[u]){
            if(!visited[v]){
                visited[v] = true;
                DFS(adj, v, visited);
            }
        }
    }

	int isEulerCircuit(int v, vector<int>adj[]){
	    // Code here
	    vector<int> degree(v, 0);
	    for(int u = 0; u<v; u++){
	        for(auto &vec: adj[u]){
	            degree[u]++;
	        }
	    }
	    
	    //first check out all non-zero degree vertices are single connected or not
	    vector<int> visited(v, false);
	    for(int u = 0; u<v; u++){
	        if(degree[u] != 0){
	            DFS(adj, u, visited);
	            break;
	        }
	    }
	    
	    for(int u = 0; u<v; u++){
	        if(degree[u] != 0 && visited[u] != true){
	            return 0;
	        }
	    }
	    
	    //If all non-zero degree vertics are connected then check for
	    //euler path or euler circuit or none
	    int countOddDegree = 0;
	    for(auto &it: degree){
	        if(it%2 != 0){
	            countOddDegree++;
	        }
	    }
	    
	    if(countOddDegree == 0){
	        return 2;
	    }else if(countOddDegree == 2){
	        return 1;
	    }else if(countOddDegree > 2){
	        return 0;
	    }
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
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends