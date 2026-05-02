class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Initialize an n x n matrix with zeros
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int val = 1;
        
        while (top <= bottom && left <= right) {
            // 1. Fill top row (left to right)
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = val++;
            }
            top++;
            
            // 2. Fill right column (top to bottom)
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = val++;
            }
            right--;
            
            // 3. Fill bottom row (right to left)
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    matrix[bottom][i] = val++;
                }
                bottom--;
            }
            
            // 4. Fill left column (bottom to top)
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    matrix[i][left] = val++;
                }
                left++;
            }
        }
        
        return matrix;
    }
};