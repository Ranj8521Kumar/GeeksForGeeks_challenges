//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int max_len=INT_MIN;
        pair<int,int>p={0,arr.size()};
        priority_queue<pair<int,int>>maxi;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>mini;
        int i=0,j=0,n=arr.size();
        
        arr.push_back(INT_MAX);
        
        while(i<n and j<=n)
        {
            maxi.push({arr[j],j});
            mini.push({arr[j],j});
            while(maxi.top().second<i)
            {
                maxi.pop();
            }
            while(mini.top().second<i)
            {
                mini.pop();
            }
            if(abs(maxi.top().first-mini.top().first)>x)
            {
                if(j-i+1 > max_len)
                {
                   p={i,j};
                   max_len=j-i+1;
                }
                i++;
            }
            j++;
        }
        vector<int>ans(arr.begin()+p.first, arr.begin()+p.second);
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends