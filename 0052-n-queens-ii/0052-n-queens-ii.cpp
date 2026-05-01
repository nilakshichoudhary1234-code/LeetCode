class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        // Tracking sets for columns and both types of diagonals
        unordered_set<int> cols;
        unordered_set<int> posDiag; // (r + c)
        unordered_set<int> negDiag; // (r - c)
        
        backtrack(0, n, count, cols, posDiag, negDiag);
        return count;
    }

private:
    void backtrack(int r, int n, int& count, 
                   unordered_set<int>& cols, 
                   unordered_set<int>& posDiag, 
                   unordered_set<int>& negDiag) {
        // Base case: All queens are placed
        if (r == n) {
            count++;
            return;
        }

        for (int c = 0; c < n; c++) {
            // If the current column or diagonals are already occupied, skip
            if (cols.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) {
                continue;
            }

            // Place queen and mark paths
            cols.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);

            // Move to the next row
            backtrack(r + 1, n, count, cols, posDiag, negDiag);

            // Remove queen and unmark paths (Backtrack)
            cols.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
        }
    }
};