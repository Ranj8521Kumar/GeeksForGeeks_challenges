class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        string result = "";
        int n = s.size();
        
        for(auto ch : s){
            while(!result.empty() && k > 0 && result.back() < ch){
                result.pop_back();
                k--;
            }
            
            result.push_back(ch);
        }
        
        while(k > 0){
            result.pop_back();
            k--;
        }
        
        return result.substr(0, n-k);
    }
};
