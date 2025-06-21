class Solution {
  public:
    // You need to complete this function

    int towerOfHanoi(int n, int from, int to, int aux) {
        // Your code here
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        int count = towerOfHanoi(n-1, from, aux, to);
        
        count += 1;
        
        count += towerOfHanoi(n-1, aux, to, from);
        
        return count;
    }
};