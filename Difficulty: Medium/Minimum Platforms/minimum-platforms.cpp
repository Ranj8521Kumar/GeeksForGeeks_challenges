class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        vector<vector<int>> pairs;
        priority_queue<int, vector<int>, greater<int>> pq;
    
        for(int i = 0; i<n; i++){
            pairs.push_back({arr[i], dep[i]});
        }
    
        sort(pairs.begin(), pairs.end());
    
        int minPlatforms = 0;
    
        for(int i = 0; i<n; i++){
            int arrival = pairs[i][0];
            int depart = pairs[i][1];
    
            // free All Platform whose train has already departed
            while(!pq.empty() && pq.top() < arrival){
                pq.pop();
            }
    
            pq.push(depart);
            minPlatforms = max(minPlatforms, (int)pq.size());
        }
    
        return minPlatforms;
        
    }
};
