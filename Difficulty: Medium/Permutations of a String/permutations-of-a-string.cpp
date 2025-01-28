//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void solve(int idx, string &s, unordered_set<string> &st){
        
        if(idx == s.size()){
            st.insert(s);
            return;
        }
        
        for(int i = idx; i<s.size(); i++){
            if(i != idx && s[i] == s[idx]){
                continue;
            }
            
            swap(s[i], s[idx]);
            
            solve(idx+1, s, st);
            
            swap(s[i], s[idx]);//for backtrackto original order
        }
    }
  
    vector<string> findPermutation(string &s) {
        // Code here there
        //using resursion
        
        sort(s.begin(), s.end());//for making all dublicate characters together
        unordered_set<string> st;
        
        solve(0, s, st);
        
        vector<string> result(st.begin(), st.end());
        
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends