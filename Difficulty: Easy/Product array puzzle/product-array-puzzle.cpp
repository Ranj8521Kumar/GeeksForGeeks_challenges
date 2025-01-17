//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        long long productWithOutZero = 1;
        int countZero = 0;
        
        for (int num : nums) {
            if (num != 0) {
                productWithOutZero *= num;
            } else {
                countZero++;
            }
        }
        
        vector<int> result(n, 0); // Initialize result with 0
        
        if (countZero > 1) {
            // If there are more than one zero, all products will be zero
            return result;
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                // If the current element is zero, set the product as productWithOutZero
                result[i] = productWithOutZero;
            } else if (countZero == 0) {
                // If there are no zeros, divide the product by the current element
                result[i] = productWithOutZero / nums[i];
            }
        }
        
        return result;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends