class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& nums) {
        // code here
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st; // Store Indices
        
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && nums[i] >= nums[st.top()]){
                st.pop();
            }
            
            if(!st.empty()){
                result[i] = nums[st.top()];
            }
            
            st.push(i);
        }
        
        return result;
    }
};