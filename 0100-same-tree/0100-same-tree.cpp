class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, the trees are identical at this point
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // If one node is null and the other isn't, or if the values differ,
        // the trees are not the same
        if (p == nullptr || q == nullptr || p->val != q->val) {
            return false;
        }
        
        // Recursively check if the left subtrees and right subtrees are the same
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};