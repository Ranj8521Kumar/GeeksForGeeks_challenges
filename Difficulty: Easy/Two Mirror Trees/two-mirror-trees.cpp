/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */

/* Given two trees, should return true if they are
   mirror of each other. */
class Solution {
  public:
    bool areMirror(Node* a, Node* b) {
        // Your code here
        if(!a && !b) return true;
        
        if(a && !b) return false;
        if(!a && b) return false;
        
        return (a->data == b->data) && areMirror(a->left, b->right)
                                    && areMirror(a->right, b->left);
    }
};