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
private:
    unordered_map<int, int> inorder_map;
    int preorder_index = 0;

    TreeNode* buildTreeHelper(const vector<int>& preorder, int inorder_start, int inorder_end) {
        // Base case: if there are no elements to construct the subtree
        if (inorder_start > inorder_end) {
            return nullptr;
        }

        // Select the current root value from preorder traversal
        int root_val = preorder[preorder_index++];
        TreeNode* root = new TreeNode(root_val);

        // Find the index of this root in the inorder traversal
        int inorder_index = inorder_map[root_val];

        // Recursively build the left and right subtrees
        // Elements to the left of inorder_index form the left subtree
        root->left = buildTreeHelper(preorder, inorder_start, inorder_index - 1);
        // Elements to the right of inorder_index form the right subtree
        root->right = buildTreeHelper(preorder, inorder_index + 1, inorder_end);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorder_map.clear();
        preorder_index = 0;

        // Build a hash map to look up inorder element indices in O(1) time
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, inorder.size() - 1);
    }
};