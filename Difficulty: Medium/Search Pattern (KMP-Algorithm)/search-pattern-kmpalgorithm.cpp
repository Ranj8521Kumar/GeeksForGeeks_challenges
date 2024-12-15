//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    void computeLPS(string &pat, vector<int>& LPS, int m){
        LPS[0] = 0;
        
        int j = 1;
        int len = 0;
        while(j < m){
            if(pat[j] == pat[len]){
                len++;
                LPS[j] = len;
                j++;
            }else{
                if(len != 0){
                    len--;
                }else{
                    LPS[j] = 0;
                    j++;
                }
            }
        }
    }
    
  public:
    vector<int> search(string& pat, string& txt) {
        int n = txt.size();
        int m = pat.size();
        
        vector<int> LPS(m, 0);
        computeLPS(pat, LPS, m);
        
        int i = 0;
        int j = 0;
        
        vector<int> result;
        
        while(i < n){
            if(txt[i] == pat[j]){
                i++;
                j++;
            }
            
            if(j == m){  // If we found a match
                result.push_back(i - m);  // Correct index for the match start
                j = LPS[j - 1];  // Use LPS to skip characters
            }else if(txt[i] != pat[j]){
                if(j != 0){
                    j = LPS[j - 1];  // Use LPS to skip some comparisons
                }else{
                    i++;  // Move to the next character in text
                }
            }
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends