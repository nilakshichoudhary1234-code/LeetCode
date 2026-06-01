class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string currentIP = "";
        // A valid IP address can have at most 12 digits (3 * 4)
        if (s.length() > 12) return result; 
        
        backtrack(s, 0, 0, currentIP, result);
        return result;
    }

private:
    void backtrack(const string& s, int index, int segments, string currentIP, vector<string>& result) {
        // If we have parsed all characters and found exactly 4 segments, it's a valid IP
        if (index == s.length() && segments == 4) {
            currentIP.pop_back(); // Remove the trailing dot
            result.push_back(currentIP);
            return;
        }
        
        // If we reached 4 segments but haven't parsed the whole string, or vice versa
        if (segments == 4 || index == s.length()) {
            return;
        }

        // Try to extract segments of length 1, 2, or 3
        for (int len = 1; len <= 3; ++len) {
            if (index + len > s.length()) break; // Out of bounds

            string part = s.substr(index, len);
            
            // Check for leading zeros (e.g., "01", "00" are invalid, but a single "0" is valid)
            if (part[0] == '0' && len > 1) break;
            
            // Check if the value is within [0, 255]
            int value = stoi(part);
            if (value > 255) break;

            // Recurse down with the current segment added
            backtrack(s, index + len, segments + 1, currentIP + part + ".", result);
        }
    }
};