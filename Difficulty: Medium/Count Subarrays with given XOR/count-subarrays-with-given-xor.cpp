class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,  int> mpp;
        long result = 0;
        
        int Xor = 0;
        
        for(auto &it: arr){
            Xor ^= it;
            if(Xor == k) result++;
            
            if(mpp.find(Xor^k) != mpp.end()){
                result += mpp[Xor^k];
            }
            
            mpp[Xor]++;
        }
        
        return result;
    }
};