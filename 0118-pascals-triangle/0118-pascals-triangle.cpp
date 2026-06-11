class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        
        for (int i = 0; i < numRows; i++) {
            // Resize the current row to hold i + 1 elements
            ans[i].resize(i + 1);
            
            // First and last elements of each row are always 1
            ans[i][0] = ans[i][i] = 1;
            
            // Fill the interior elements
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        
        return ans;
    }
};