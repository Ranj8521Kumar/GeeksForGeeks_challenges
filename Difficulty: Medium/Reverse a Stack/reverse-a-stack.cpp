// User function Template for C++

class Solution {
  public:
    void insertAtButtom(stack<int> &st, int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        
        int temp = st.top();
        st.pop();
        insertAtButtom(st, x);
        
        st.push(temp);
    }
  
    void Reverse(stack<int> &st) {
        if(st.empty()){
            return;
        }
        
        int x = st.top();
        st.pop();
        Reverse(st);
        
        insertAtButtom(st, x);
    }
};