//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        int n1 = s1.size();
        int n2 = s2.size();
        
        if(n1 != n2) return false;
        
        unordered_map<char, int> mpp;
        
        for(auto &ch: s1){
            mpp[ch]++;
        }
        
        for(auto &ch: s2){
            mpp[ch]--;
        }
        
        for(auto it: mpp){
            if(it.second != 0){
                return false;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends