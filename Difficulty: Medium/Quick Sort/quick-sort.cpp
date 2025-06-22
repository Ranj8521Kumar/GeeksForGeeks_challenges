class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        
        if(low >= high) return;
        
            int pivot = partition(arr, low, high);
            
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        // code here
        int pivot = arr[high];
        int j = low - 1;
        
        for(int i = low; i < high; i++){
            if(arr[i] <= pivot){
                j++;
                swap(arr[i], arr[j]);
            }
        }
        
        swap(arr[j+1], arr[high]);
        
        return j+1;
    }
};