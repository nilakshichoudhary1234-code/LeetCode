class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int boxes[9][9] = {0};
        
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                
                int num = board[r][c] - '1'; // Convert '1'-'9' to index 0-8
                int box_index = (r / 3) * 3 + (c / 3);
                
                if (rows[r][num] || cols[c][num] || boxes[box_index][num]) {
                    return false;
                }
                
                rows[r][num] = 1;
                cols[c][num] = 1;
                boxes[box_index][num] = 1;
            }
        }
        
        return true;
    }
};