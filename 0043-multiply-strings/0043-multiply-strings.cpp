class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.size();
        int n = num2.size();
        // Result can have at most m + n digits
        vector<int> res(m + n, 0);
        
        // Multiply each digit from right to left
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + res[i + j + 1];
                
                // Update the current position and carry to the next
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }
        
        // Convert the result vector back to a string
        string result = "";
        for (int digit : res) {
            // Skip leading zeros
            if (!(result.empty() && digit == 0)) {
                result += to_string(digit);
            }
        }
        
        return result.empty() ? "0" : result;
    }
};