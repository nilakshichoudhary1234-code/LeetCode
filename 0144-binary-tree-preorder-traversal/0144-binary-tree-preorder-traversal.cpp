class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        
        stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode* curr = s.top();
            s.pop();
            
            // 1. Visit the root/current node
            result.push_back(curr->val);
            
            // 2. Push right child first (so left is processed first)
            if (curr->right != nullptr) {
                s.push(curr->right);
            }
            // 3. Push left child
            if (curr->left != nullptr) {
                s.push(curr->left);
            }
        }
        
        return result;
    }
};