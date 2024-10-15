//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int subArraySum(vector<int>& arr, int tar) {
        int n = arr.size();
        int count = 0, sum = 0;
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;

        for(int i = 0; i < n; i++) {
            sum += arr[i];

            if(prefixSum.find(sum - tar) != prefixSum.end()) {
                count += prefixSum[sum - tar];
            }

            prefixSum[sum]++;
        }

        return count;
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
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends