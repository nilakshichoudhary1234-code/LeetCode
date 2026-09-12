class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string res = "1";
        
        // Generate sequences from 2 to n
        for (int i = 2; i <= n; i++) {
            string next_res = "";
            int count = 1;
            
            for (int j = 0; j < res.length(); j++) {
                // If the next character is the same, increment count
                if (j + 1 < res.length() && res[j] == res[j+1]) {
                    count++;
                } else {
                    // Otherwise, append count and the digit itself
                    next_res += to_string(count) + res[j];
                    count = 1; // Reset count for the next digit
                }
            }
            res = next_res;
        }
        
        return res;
    }
};