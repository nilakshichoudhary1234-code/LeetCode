class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            // Shift to 0-indexed to handle the 1-26 mapping correctly
            columnNumber--; 
            
            // Get the current character
            char c = 'A' + (columnNumber % 26);
            result += c;
            
            // Move to the next positional digit
            columnNumber /= 26;
        }
        
        // Since we gathered characters from right to left, reverse the result
        reverse(result.begin(), result.end());
        return result;
    }
};