//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to find position of first set bit in the given number.
    int getFirstSetBit(int n) {
        // Your code here
        int position = 1;
        
        while(n != 0){
            if(n%2 == 1){
                return position;
            }else{
                position++;
            }
            
            n = n/2;
        }
        
        
        return 0;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t; // testcases
    while (t--) {
        int n;
        cin >> n; // input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends