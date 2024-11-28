//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int myAtoi(char *s) {
        int i = 0;
        int result = 0;
        bool negativeNum = false;

        // Skip leading spaces
        while (s[i] == ' ') {
            i++;
        }

        // Handle optional sign
        if (s[i] == '-' || s[i] == '+') {
            negativeNum = (s[i] == '-');
            i++;
        }

        // Convert digits to integer
        while (isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow/underflow
            if (result > (INT_MAX - digit) / 10) {
                return negativeNum ? INT_MIN : INT_MAX;
            }

            result = result * 10 + digit;
            i++;
        }

        return negativeNum ? -result : result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends