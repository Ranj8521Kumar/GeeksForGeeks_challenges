//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> result;
        
        int left = 0;
        int right = n-1;
        int top = 0;
        int buttom = m-1;
        
        while(left <=  right && top<=buttom){
            for(int j = left; j<=right; j++){//for left
                result.push_back(mat[top][j]);
            }
            top++;
            
            for(int i = top; i<=buttom; i++){//for down
                result.push_back(mat[i][right]);
            }
            right--;
            
            if(top <= buttom){
                for(int j = right; j>=left; j--){//for left
                    result.push_back(mat[buttom][j]);
                }
                buttom--;
            }
            
            if(left<=right){
                for(int i = buttom; i>=top; i--){//for up
                    result.push_back(mat[i][left]);
                }
                left++;
            }
            
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends