//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    int merge(vector<int>& arr, int low, int high){
        int count = 0;
        int mid = (low+high)/2;
        
        int left = low, right = mid+1;
        
        vector<int> temp;
        
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left++]);
            }else{
                temp.push_back(arr[right++]);
                count += (mid-left+1);
            }
        }
        
        while(left<=mid){
            temp.push_back(arr[left++]);
        }
        
        while(right<=high){
            temp.push_back(arr[right++]);
        }
        
        for(int i = low; i<=high; i++){ // Copy sorted elements back to original array
            arr[i] = temp[i-low];
        }
        
        return count;
    }
  
  
    int mergeSort(vector<int>& arr, int low, int high){
        if(low>=high) return 0;
        
        int count = 0;
        int mid = (low+high)/2;
        
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid+1, high);
        count += merge(arr, low, high);
        
        return count;
    }
    
    
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        
        return mergeSort(arr, 0, n-1);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends