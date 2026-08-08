#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
    int rows, cols;

    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int index) {
        if (index == word.length()) {
            return true;
        }

        // Check boundaries and character match
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[index]) {
            return false;
        }

        // Mark the current cell as visited in-place
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore adjacent cells: Up, Down, Left, Right
        bool found = dfs(board, word, r + 1, c, index + 1) ||
                     dfs(board, word, r - 1, c, index + 1) ||
                     dfs(board, word, r, c + 1, index + 1) ||
                     dfs(board, word, r, c - 1, index + 1);

        // Backtrack (restore original character)
        board[r][c] = temp;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        if (word.length() > rows * cols) {
            return false;
        }

        // --- Pruning 1: Character frequency check ---
        unordered_map<char, int> boardCounts;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                boardCounts[board[r][c]]++;
            }
        }

        unordered_map<char, int> wordCounts;
        for (char ch : word) {
            wordCounts[ch]++;
            if (wordCounts[ch] > boardCounts[ch]) {
                return false; // Not enough instances of character in board
            }
        }

        // --- Pruning 2: Reverse search direction ---
        // If the frequency of the starting character is higher than the ending character,
        // search in reverse to minimize branching.
        if (boardCounts[word.front()] > boardCounts[word.back()]) {
            reverse(word.begin(), word.end());
        }

        // Find starting cell
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == word[0]) {
                    if (dfs(board, word, r, c, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};