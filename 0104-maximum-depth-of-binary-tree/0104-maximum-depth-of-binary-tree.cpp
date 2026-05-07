/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        // Recursive calls to find height of children
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        
        // Return the greater of the two heights + 1 for the current node
        return max(leftHeight, rightHeight) + 1;
        
    }
};