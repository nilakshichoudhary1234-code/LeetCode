class Solution {
public:
    int numTrees(int n) {
        // G[i] stores the number of unique BSTs with i nodes
        vector<int> G(n + 1, 0);
        
        // Base cases
        G[0] = 1; // Empty tree
        G[1] = 1; // Single node tree
        
        // Fill the DP table
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                // j represents the root node
                // Left subtree has j-1 nodes, Right subtree has i-j nodes
                G[i] += G[j - 1] * G[i - j];
            }
        }
        
        return G[n];
    }
};