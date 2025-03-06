//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  vector<vector<int>> dp; // Memoization table

    int abc(string &s1, string &s2, int i, int j) {
        
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + abc(s1, s2, i - 1, j - 1);
        } 
        
        else {
            return dp[i][j] = max(abc(s1, s2, i - 1, j), abc(s1, s2, i, j - 1));
        }
    }
  
  
    int lcs(string &s1, string &s2) {
        // code here
        int m = s1.size(), n = s2.size();
        dp.assign(m, vector<int>(n, -1)); 
        return abc(s1, s2, m - 1, n - 1);
       
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends