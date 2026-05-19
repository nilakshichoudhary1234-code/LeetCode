class Solution {
private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = new TreeNode(INT_MIN); // Initialize with minimum possible value

public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        
        // Swap the values of the two misplaced nodes
        if (first && second) {
            swap(first->val, second->val);
        }
    }

private:
    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // Detect a violation: previous node is greater than the current node
        if (prev->val > root->val) {
            if (!first) {
                first = prev; // First violation pointer points to prev
            }
            second = root;    // Second violation pointer always updates to current
        }
        prev = root; // Move prev pointer forward

        inorder(root->right);
    }
};