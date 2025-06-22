// User function Template for C++

/* Node of the binary search tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node *flattenBST(Node *root) {
        // code here
        if(!root) return nullptr;
        
        Node* head = flattenBST(root->left);
        root->left = nullptr;
        
        
        if(head != nullptr){
            Node *temp = head;
            while(temp && temp->right){
                temp = temp->right;
            }
            
            temp->right = root;
        }else{
            head = root;
        }
        
        
        root->right = flattenBST(root->right);
        
        return head;
    }
};