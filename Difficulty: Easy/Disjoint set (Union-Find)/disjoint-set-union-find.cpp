//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int find(int a[],int x);
void unionSet(int a[],int x ,int z);
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
			a[i]=i;
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			string s;
			cin>>s;
			if(s=="UNION"){
				int z,x;
				cin>>x>>z;
				unionSet(a,x,z);
			}
			else{
				int x;
				cin>>x;
				int parent=find(a,x);
				cout<<parent<<" ";
			}
		}
		cout<<endl;
	
cout << "~" << "\n";
}
}
// } Driver Code Ends

int find(int A[], int x) {
    // Path compression: make every node point directly to the root
    if (A[x] != x) {
        A[x] = find(A, A[x]); // Recursively find the root and compress the path
    }
    return A[x];
}

void unionSet(int A[], int x, int z) {
    // Find roots of x and z
    int x_parent = find(A, x);
    int z_parent = find(A, z);

    // If they are not already in the same set
    if (x_parent != z_parent) {
        // Union: attach one root to the other
        A[x_parent] = z_parent;
    }
}
