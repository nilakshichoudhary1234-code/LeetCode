
#include <string>
#include <vector>

class Solution {
public:
    string convert(string s, int numRows) {
        // Base case: if numRows is 1 or greater than string length, no zigzag needed
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Create a list of strings for each row
        std::vector<std::string> rows(std::min(static_cast<int>(s.length()), numRows));
        
        int currRow = 0;
        bool goingDown = false;

        // Traverse the input string
        for (char c : s) {
            rows[currRow] += c;
            
            // Change direction when reaching the top or bottom row
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move up or down based on current direction
            currRow += goingDown ? 1 : -1;
        }

        // Concatenate all rows into a single string result
        std::string result;
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};