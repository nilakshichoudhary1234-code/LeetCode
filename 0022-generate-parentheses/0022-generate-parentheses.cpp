class Solution {
public:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // Base case: The string has reached the maximum length (n pairs)
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Rule 1: Add an opening bracket if possible
        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }

        // Rule 2: Add a closing bracket if it won't break well-formedness
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};