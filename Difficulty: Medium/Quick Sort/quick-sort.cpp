class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low >= high) return;
        
        int pi = partition(arr, low,  high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
        
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        int pi = low;
        int pivot = arr[high];
        
        for(int i = low; i<high; i++){
            if(arr[i] <= pivot){
                swap(arr[pi], arr[i]);
                pi++;
            }
        }
        
        swap(arr[pi], arr[high]);
        return pi;
    }
};