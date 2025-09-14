class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int sum = 0;
        int maxSum = INT_MIN;
        
        for(auto &it: arr){
            sum += it;
            
            maxSum = max(maxSum, sum);
            if(sum < 0) sum = 0;
        }
        
        return maxSum;
    }
};