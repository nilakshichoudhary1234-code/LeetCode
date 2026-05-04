class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string segment;
        vector<string> stack;
        
        // Split by '/'
        while (getline(ss, segment, '/')) {
            if (segment == "" || segment == ".") {
                continue;
            }
            if (segment == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(segment);
            }
        }
        
        // Build the result
        string result = "";
        for (const string& dir : stack) {
            result += "/" + dir;
        }
        
        return result.empty() ? "/" : result;
    }
};