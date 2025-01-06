//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        if(n < 2) return {};
        
        sort(begin(arr),end(arr));
        
        int i = 0 , j = n-1;
        int diff = INT_MAX;
        int val1 = -1 , val2 = -1;
        
        while(i < j) {
            int d = abs(target - (arr[i]+arr[j]));
            
            if(d < diff) {
                diff = d;
                val1 = arr[i];
                val2 = arr[j];
            }
            if(arr[i]+arr[j] < target) {
                i++;
            }
            else if(arr[i]+arr[j] >= target) {
                j--;
            }
        }
        return {val1 , val2};
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
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends