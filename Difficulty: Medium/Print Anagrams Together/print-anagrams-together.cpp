//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    vector<int> pencil(string s){
        
        vector<int>v(26);
        
        for(char c : s){
            v[c-'a']++;
        }
        
        return v;
    }
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        
        map<vector<int>, int>mp;
        vector<vector<string>>ans;
        int track = -1;
        
        for(string s : arr){
            
            vector<int>v = pencil(s);
            
            if(mp.find(v) == mp.end()){
                track++;
                ans.push_back({s});
                mp[v] = track;
            }
            else{
                ans[mp[v]].push_back(s);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends