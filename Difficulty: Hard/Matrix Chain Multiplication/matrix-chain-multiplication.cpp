class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<vector<int>> cost(n+1, vector<int> (n+1, INT_MIN));
        
        return mc(1, n-1, cost, arr);
    }
    
    int mc(int i, int j, vector<vector<int>> &cost, vector<int> &arr){
        if(i == j){
            cost[i][j] = 0;
            return 0;
        }
        
        if(cost[i][j] != INT_MIN){
            return cost[i][j];
        }
        
        int costMUl = INT_MAX;
        for(int k = i; k <= j-1; k++){
            costMUl = min(costMUl, mc(i, k, cost, arr) + mc(k+1, j, cost, arr) + arr[i-1]*arr[k]*arr[j]);
        }
        
        cost[i][j] = costMUl;
        return costMUl;
    }
};