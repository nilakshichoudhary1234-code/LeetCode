class Solution {
public:
    // Helper function to compute height of a complete tree (leftmost path)
    int getHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->left;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int hL = getHeight(root->left);
        int hR = getHeight(root->right);

        if (hL == hR) {
            // Left subtree is perfect. 
            // Total = (Nodes in left + root) + recurse right
            // 1 << hL is 2^hL
            return (1 << hL) + countNodes(root->right);
        } else {
            // Right subtree is perfect.
            // Total = (Nodes in right + root) + recurse left
            return (1 << hR) + countNodes(root->left);
        }
    }
};