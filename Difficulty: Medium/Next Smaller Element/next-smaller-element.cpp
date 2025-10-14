class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& nums) {
        //  code here
        int n = nums.size();
        stack<int> st; // Store Indices
        vector<int> result(n, -1);
        
        for(int i = n-1; i>=0; i--){
            while(!st.empty()){
                if(nums[i] <= nums[st.top()]){
                    st.pop();
                }else{
                    break;
                }
            }
            
            if(!st.empty()){
                result[i] = nums[st.top()];
            }
            st.push(i);
        }
        
        return result;
    }
};