class Solution {
  public:
    vector<int> prevSmaller(vector<int>& nums) {
        //  code here
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st; //Store Indices
        
        for(int i = 0; i<n; i++){
            while(!st.empty() && nums[i] <= nums[st.top()]){
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