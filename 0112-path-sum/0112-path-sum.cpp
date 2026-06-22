/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: if the node is null, no path exists
        if (root == nullptr) {
            return false;
        }
        
        // Subtract the current node's value from targetSum
        targetSum -= root->val;
        
        // Check if it's a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == 0;
        }
        
        // Recursively check the left and right subtrees
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};