//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int getMinDiff(int k, vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int ans = arr[n - 1] - arr[0];
        int ma, mi;
        int largest = arr[n - 1] - k;
        int smallest = arr[0] + k;

        for (int i = 0; i < n - 1; i++) {
            mi = min(smallest, arr[i + 1] - k);
            ma = max(largest, arr[i] + k);
            ans = min(ans, ma - mi);
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
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends