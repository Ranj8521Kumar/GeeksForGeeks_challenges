/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void traverse(Node* root, vector<Node*>& inorder){
        if(!root) return;
        
        traverse(root->left, inorder);
        inorder.push_back(root);
        traverse(root->right, inorder);
    }
  
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> inorder;
        traverse(root, inorder);
        
        Node* pre = nullptr;
        Node* suc = nullptr;
        int n = inorder.size();
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(inorder[mid]->data < key){
                pre = inorder[mid];
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        
        low = 0;
        high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(inorder[mid]->data > key){
                suc = inorder[mid];
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return {pre, suc};
    }
};