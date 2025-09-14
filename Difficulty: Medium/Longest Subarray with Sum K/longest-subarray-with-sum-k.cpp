class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mpp;
        int sum = 0;
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            sum += arr[i];
            
            if(sum == k){
                ans = max(ans, i+1);
            }
            
            int rest = sum - k;
            if(mpp.find(rest) != mpp.end()){
                ans = max(ans, i - mpp[rest]);
            }
            
            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;
            }
        }
        
        return ans;
    }
};