/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void inOrderTraversal(Node* root, vector<Node*> &inorder) {
        if(root == nullptr) return;

        inOrderTraversal(root->left, inorder);
        inorder.push_back(root);
        inOrderTraversal(root->right, inorder);
    }

    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> inorder;
        inOrderTraversal(root, inorder);
        int n = inorder.size();
        vector<Node*> result(2, nullptr); // {predecessor, successor}

        // If key exists in tree
        for (int i = 0; i < n; ++i) {
            if (inorder[i]->data == key) {
                if (i > 0) result[0] = inorder[i - 1];
                if (i < n - 1) result[1] = inorder[i + 1];
                return result;
            }
        }

        // Key doesn't exist, use lower_bound
        auto lb = lower_bound(inorder.begin(), inorder.end(), key, [](Node* a, int val) {
            return a->data < val;
        });

        int idx = lb - inorder.begin();

        if (idx > 0) result[0] = inorder[idx - 1]; // predecessor
        if (idx < n) result[1] = inorder[idx];     // successor

        return result;
    }
};
