//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
    private :
    void reverse(string &str)
    {
       int s=0;
       int e=str.size()-1;
       while(s<e)
       {
           swap(str[s],str[e]);
           s++;
           e--;
       }
    }
  public:
    string roundToNearest(string str) {
        // Complete the function
        int ind=str.size();
        int n=str[ind-1]-'0';
        if(n<=5)
        {
              string ans="";
              for(int i=0;i<ind-1;i++)
              {
                  ans+=str[i];
              }
              ans=ans+'0';
              return ans;
        }
        else 
        {
        string ans="";
        int sum=0;
        int carry=1;
        
        for(int i=ind-2;i>=0;i--)
        {
            int n=str[i]-'0'+carry;
            int ld=n%10;
            carry=n/10;
            ans+=to_string(ld);
            
            
        }
        if(carry!=0)
        {
            ans+=to_string(carry);
        }
        reverse(ans);
        return (ans+'0');
        }
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends