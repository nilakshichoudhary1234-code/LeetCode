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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }

private:
    vector<TreeNode*> buildTrees(int start, int end) {
        vector<TreeNode*> all_trees;
        
        // Base case: If start > end, no elements left to form a subtree.
        // We push nullptr to represent an empty subtree.
        if (start > end) {
            all_trees.push_back(nullptr);
            return all_trees;
        }
        
        // Iterate through all values to make each the root of the tree
        for (int i = start; i <= end; ++i) {
            // Generate all unique left and right subtrees
            vector<TreeNode*> left_trees = buildTrees(start, i - 1);
            vector<TreeNode*> right_trees = buildTrees(i + 1, end);
            
            // Connect left and right subtrees to the root 'i'
            for (TreeNode* left : left_trees) {
                for (TreeNode* right : right_trees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    all_trees.push_back(root);
                }
            }
        }
        
        return all_trees;
    }
};