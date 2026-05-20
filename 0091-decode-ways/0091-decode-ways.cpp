class Solution {
public:
    int numDecodings(string s) {
        // A leading zero means the entire string cannot be validly decoded
        if (s.empty() || s[0] == '0') return 0;
        
        int n = s.length();
        
        // p2 represents dp[i-2], p1 represents dp[i-1]
        int p2 = 1; // Base case: empty string has 1 way
        int p1 = 1; // Base case: first valid character has 1 way
        
        for (int i = 1; i < n; ++i) {
            int current_ways = 0;
            
            // Check if the single digit is valid (1-9)
            if (s[i] != '0') {
                current_ways += p1;
            }
            
            // Check if the two-digit combination is valid (10-26)
            int two_digit = stoi(s.substr(i - 1, 2));
            if (two_digit >= 10 && two_digit <= 26) {
                current_ways += p2;
            }
            
            // If at any point it's impossible to decode, we can return early
            if (current_ways == 0) return 0;
            
            // Move our pointers forward for the next iteration
            p2 = p1;
            p1 = current_ways;
        }
        
        return p1;
    }
};