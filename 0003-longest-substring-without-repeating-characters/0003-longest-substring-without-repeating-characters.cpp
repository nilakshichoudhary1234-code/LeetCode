
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Array to store the last seen index of each ASCII character
        vector<int> charIndex(128, -1);
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // If the character was seen before and is within the current window
            if (charIndex[s[right]] >= left) {
                left = charIndex[s[right]] + 1;
            }
            
            // Update the last seen index of the character
            charIndex[s[right]] = right;
            
            // Calculate the max length found so far
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};