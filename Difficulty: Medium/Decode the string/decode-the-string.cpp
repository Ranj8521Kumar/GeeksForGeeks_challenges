//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<string> st;
        stack<int> numStack;
        string currentString = "";
        int num =  0;
        
        for(auto &ch : s){
            if(isdigit(ch)){
                num = num*10 + (ch - '0');
            }else if(ch ==  '['){
                st.push(currentString);
                currentString = "";
                
                numStack.push(num);
                num = 0;
            }else if(ch == ']'){
                string temp = currentString;
                currentString = st.top();
                st.pop();
                
                int repeat = numStack.top();
                numStack.pop();
                
                while(repeat--){
                    currentString += temp;
                }
            }else{
                currentString += ch;
            }
        }
        
        return currentString;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends