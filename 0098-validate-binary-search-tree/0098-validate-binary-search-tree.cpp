class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }

private:
    bool validate(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        // An empty tree is a valid BST
        if (node == nullptr) {
            return true;
        }

        // Check if the current node's value violates the min/max constraints
        if ((minNode && node->val <= minNode->val) || (maxNode && node->val >= maxNode->val)) {
            return false;
        }

        // Recursively validate subtrees with updated constraints:
        // Left subtree values must be < node->val
        // Right subtree values must be > node->val
        return validate(node->left, minNode, node) && 
               validate(node->right, node, maxNode);
    }
};