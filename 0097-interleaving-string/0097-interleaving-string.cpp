#include <string>
#include <vector>

class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        // Edge case: If total lengths don't match, it's impossible.
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        
        // Ensure s2 is the smaller string if you want to strictly minimize space, 
        // but given constraints (<= 100), a vector of s2.length() + 1 is perfectly fine.
        std::vector<bool> dp(s2.length() + 1, false);
        
        for (int i = 0; i <= s1.length(); ++i) {
            for (int j = 0; j <= s2.length(); ++j) {
                if (i == 0 && j == 0) {
                    dp[j] = true; // Base case
                } else if (i == 0) {
                    // First row: can only take characters from s2
                    dp[j] = dp[j - 1] && (s2[j - 1] == s3[i + j - 1]);
                } else if (j == 0) {
                    // First column: can only take characters from s1
                    // dp[j] here represents dp[i-1][0] from the previous iteration
                    dp[j] = dp[j] && (s1[i - 1] == s3[i + j - 1]);
                } else {
                    // General case: 
                    // dp[j] (on the right) is from the previous row (s1 match)
                    // dp[j-1] is from the current row (s2 match)
                    dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || 
                            (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        
        return dp[s2.length()];
    }
};