#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        // If the input string is empty, return an empty list immediately
        if (digits.empty()) {
            return {};
        }

        // Mapping from digit to letters
        std::unordered_map<char, std::string> phone = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        std::vector<std::string> result;
        std::string currentPath = "";
        
        backtrack(0, digits, currentPath, phone, result);
        return result;
    }

private:
    void backtrack(int index, const std::string& digits, std::string& currentPath,
                   const std::unordered_map<char, std::string>& phone, 
                   std::vector<std::string>& result) {
        // Base Case: If the current path length matches the input digits length,
        // we have successfully formed a complete combination.
        if (currentPath.length() == digits.length()) {
            result.push_back(currentPath);
            return;
        }

        // Get the letters that the current digit maps to
        char currentDigit = digits[index];
        const std::string& possibleLetters = phone.at(currentDigit);

        // Explore all options for the current digit
        for (char letter : possibleLetters) {
            currentPath.push_back(letter);              // Choose: Add letter to current path
            backtrack(index + 1, digits, currentPath, phone, result); // Explore: Move to the next digit
            currentPath.pop_back();                     // Unchoose: Backtrack (remove the letter)
        }
    }
};