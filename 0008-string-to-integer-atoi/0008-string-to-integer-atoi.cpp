class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        
        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Step 2: Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        
        // Step 3: Convert digits
        long result = 0; // use long to detect overflow
        
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Step 4: Handle overflow
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        return sign * result;
    }
};