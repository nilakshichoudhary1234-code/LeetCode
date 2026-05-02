class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        
        // dp[i][j] will be true if the first i characters of s 
        // match the first j characters of p
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        
        // Empty string matches empty pattern
        dp[0][0] = true;
        
        // Handle patterns with '*' that can match an empty string
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    // Current characters match
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // '*' matches empty sequence (dp[i][j-1]) 
                    // or matches at least one character (dp[i-1][j])
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
        
        return dp[n][m];
    }
};