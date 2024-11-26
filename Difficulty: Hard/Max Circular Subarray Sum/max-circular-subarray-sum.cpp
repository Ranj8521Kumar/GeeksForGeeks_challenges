//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();
        
        // Function to find maximum subarray sum using Kadane's algorithm
        auto kadane = [](const vector<int> &a) {
            int max_sum = a[0], current_sum = a[0];
            for (int i = 1; i < a.size(); i++) {
                current_sum = max(a[i], current_sum + a[i]);
                max_sum = max(max_sum, current_sum);
            }
            return max_sum;
        };

        //Maximum sum without considering circular property
        int max_kadane = kadane(arr);

       //Maximum sum considering the circular property
        int total_sum = 0;
        for (int i = 0; i < n; i++) {
            total_sum += arr[i];
            arr[i] = -arr[i]; // Negate the array elements
        }

        int max_wrap = total_sum + kadane(arr); // Inverting the negated result gives min sum

        // Handle case where all elements are negative
        if (max_wrap == 0) return max_kadane;

        // Return the maximum of the two cases
        return max(max_kadane, max_wrap);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends