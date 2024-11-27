//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        
        // Segregate positive numbers
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                swap(arr[i], arr[j]);
                j++;
            }
        }

        // Work on the positive segment of the array (size j)
        for (int i = 0; i < j; i++) {
            int num = abs(arr[i]);
            if (num - 1 < j && arr[num - 1] > 0) {
                arr[num - 1] = -arr[num - 1];
            }
        }

        // Find the first missing positive number
        for (int i = 0; i < j; i++) {
            if (arr[i] > 0) return i + 1;
        }

        // If all numbers 1 to j are present, return j + 1
        return j + 1;
    }
};


//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends