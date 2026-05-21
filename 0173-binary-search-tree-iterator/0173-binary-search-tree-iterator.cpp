#include <stack>

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

class BSTIterator {
private:
    std::stack<TreeNode*> nodeStack;

    // Helper function to push all left descendants of a given node onto the stack
    void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
            nodeStack.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        // Initialize the stack with the leftmost path starting from the root
        pushAllLeft(root);
    }
    
    int next() {
        // The top of the stack is the next smallest element
        TreeNode* topNode = nodeStack.top();
        nodeStack.pop();
        
        // If the popped node has a right child, 
        // we must push all left descendants of that right child
        if (topNode->right != nullptr) {
            pushAllLeft(topNode->right);
        }
        
        return topNode->val;
    }
    
    bool hasNext() {
        // If the stack is not empty, there are still elements left to traverse
        return !nodeStack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */