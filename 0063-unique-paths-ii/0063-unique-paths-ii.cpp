#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // Edge case: If the starting or ending cell has an obstacle, no paths exist
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        
        // dp array to store the number of paths for the current row
        std::vector<long long> dp(n, 0);
        dp[0] = 1; // Base case: 1 way to start at the top-left corner
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0; // Obstacle blocks all paths
                } else if (j > 0) {
                    dp[j] += dp[j - 1]; // Paths from above (dp[j]) + paths from left (dp[j-1])
                }
            }
        }
        
        return dp[n - 1];
    }
};