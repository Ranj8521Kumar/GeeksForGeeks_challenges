//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int i = 0, j = 1, maxi = 0;
        vector<int> ans;
        
        while(i < k) {
            if(arr[i] > maxi) maxi = arr[i];
            i++;
        }
        ans.push_back(maxi);
        
        while(i < n) {
            if(arr[j-1]==maxi)
                maxi = *max_element(arr.begin()+j,arr.begin()+i+1);
            else if(arr[i]>maxi) 
                maxi = arr[i];
            ans.push_back(maxi);
            i++; j++;
        }
        
        return ans;
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

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends