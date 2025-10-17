/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> result;
        if(!root) return result;
        
        queue<pair<Node*, int>> que; // {node, col}
        que.push({root, 0});
        map<int, int> mpp; // {col, value}
        
        while(!que.empty()){
            auto &p = que.front();
            que.pop();
            
            int col = p.second;
            int value = p.first->data;
            
            if(mpp.find(col) == mpp.end()){
                mpp[col] = value;
            }
            
            if(p.first->left){
                que.push({p.first->left, col - 1});
            }
            
            if(p.first->right){
                que.push({p.first->right, col + 1});
            }
        }
        
        for(auto &it: mpp){
            result.push_back(it.second);
        }
        
        return result;
    }
};