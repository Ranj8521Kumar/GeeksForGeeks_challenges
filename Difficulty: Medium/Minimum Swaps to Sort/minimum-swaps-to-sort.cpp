//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        int count = 0;

        // Pair elements with their indices and sort by value
        vector<pair<int, int>> sorted(n);
        for (int i = 0; i < n; i++) {
            sorted[i] = {arr[i], i};
        }
        sort(sorted.begin(), sorted.end());

        // Use the array itself to detect and resolve cycles
        for (int i = 0; i < n; i++) {
            // Skip if already in the correct position or visited (cycle resolved)
            while (sorted[i].second != i) {
                int correctIndex = sorted[i].second;
                swap(sorted[i], sorted[correctIndex]);
                count++;
            }
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
        Solution obj;
        cout << obj.minSwaps(arr) << endl;
    }
}

// } Driver Code Ends