//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int ans = 0;
        for (int i = 0; i < arr.size() - 2; i++) {
            int left = i + 1;
            int right = arr.size() - 1;
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum < target)
                    left++;
                else if (sum > target)
                    right--;
                else {
                    int count1 = 0;
                    int count2 = 0;
                    int elm1 = arr[left];
                    int elm2 = arr[right];
                    while (left <= right && arr[left] == elm1) {
                        count1++;
                        left++;
                    }
                    while (left <= right && arr[right] == elm2) {
                        count2++;
                        right--;
                    }
                    if (elm1 == elm2)
                        ans += count1 * (count1 - 1) / 2;
                    else
                        ans += count1 * count2;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends