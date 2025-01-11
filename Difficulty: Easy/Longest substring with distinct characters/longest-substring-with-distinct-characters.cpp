//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        vector<bool> vis(26, false);
        
        int n = s.size();
        int i = 0;
        int j = 0;
        
        int count = 0;
        
        while(j < n){
            while(vis[s[j] - 'a'] == true){
               vis[s[i] - 'a'] = false;
               i++;
            }
            
            vis[s[j] - 'a'] = true;
            count = max(count, j - i + 1);
            j++;
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends