//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool checkSorted(vector<int>& arr) {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == i + 1)
                continue;
            else
                count++;
        }

        if (count == 3 || count == 0)
            return true;

        if (count == 4) {
            for (int i = 0; i < n; i++) {
                if (arr[i] != i + 1 && arr[arr[i] - 1] == i + 1)
                    count--;
                else if (arr[i] == i + 1)
                    continue;
                else
                    return false;
            }
            if (count == 0)
                return true;
        }

        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends