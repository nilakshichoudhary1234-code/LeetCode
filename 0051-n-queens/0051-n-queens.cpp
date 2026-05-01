class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> board(n, string(n, '.'));
        
        // Sets to track occupied paths
        unordered_set<int> cols;
        unordered_set<int> posDiag; // (r + c)
        unordered_set<int> negDiag; // (r - c)
        
        backtrack(0, n, board, results, cols, posDiag, negDiag);
        return results;
    }

private:
    void backtrack(int r, int n, vector<string>& board, vector<vector<string>>& results,
                   unordered_set<int>& cols, unordered_set<int>& posDiag, unordered_set<int>& negDiag) {
        if (r == n) {
            results.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            // Check if the position is under attack
            if (cols.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) {
                continue;
            }

            // "Choose"
            cols.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);
            board[r][c] = 'Q';

            // "Explore"
            backtrack(r + 1, n, board, results, cols, posDiag, negDiag);

            // "Un-choose" (Backtrack)
            cols.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
            board[r][c] = '.';
        }
    }
};