//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        unordered_map<long long, int> prefixSum; //{prefixSum, index}
        long long currentSum = 0;
        int maxLen = 0;
        
        for(int i = 0; i<n; i++){
            currentSum += arr[i];
            
            if(currentSum == k){
                maxLen = max(maxLen, i+1);
            }
            
            long long rem = currentSum - k;
            if(prefixSum.find(rem) != prefixSum.end()){
                int len = i  - prefixSum[rem];
                maxLen = max(maxLen, len);
            }
            
            if(prefixSum.find(currentSum) == prefixSum.end()){
                prefixSum[currentSum] = i;
            }
        }
        
        return maxLen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends