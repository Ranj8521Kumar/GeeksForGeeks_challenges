//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isSafe(int row, int col, vector<int>& queens) {
        for (int i = 0; i < col; ++i) {
            int placed_row = queens[i];
            if (placed_row == row || abs(placed_row - row) == abs(i - col)) {
                return false;
            }
        }
        return true;
    }
    
    void solveNQueens(int col, int n, vector<int>& queens, vector<vector<int>>& solutions) {
        if (col == n) {
            solutions.push_back(queens);
            return;
        }
        
        for (int row = 1; row <= n; ++row) {
            if (isSafe(row, col, queens)) {
                queens[col] = row;
                solveNQueens(col + 1, n, queens, solutions);
                queens[col] = 0;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> solutions;
        vector<int> queens(n, 0);
        solveNQueens(0, n, queens, solutions);
        return solutions;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends