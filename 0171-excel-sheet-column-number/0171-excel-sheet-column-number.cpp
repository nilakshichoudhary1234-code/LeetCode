class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (char c : columnTitle) {
            // Convert character to its 1-26 mapped value
            int d = c - 'A' + 1;
            // Shift the current result by base 26 and add the new digit
            // Using long long for result prevents overflow during intermediate operations if constraints change,
            // though standard int is sufficient for "FXSHRXW".
            result = result * 26 + d;
        }
        return result;
    }
};