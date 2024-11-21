//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        int maxProfit = 0;
        
        int i = 0;
        int j = 1;
        
        while(j<n){
            if(prices[j]<prices[j-1]){
                maxProfit += prices[j-1] -  prices[i];
                i = j;
            }
            j++;
        }
        maxProfit += prices[n-1] -  prices[i];
        return maxProfit;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends