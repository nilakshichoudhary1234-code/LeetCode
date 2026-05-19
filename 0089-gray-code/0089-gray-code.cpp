class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int numElements = 1 << n; // Equivalent to 2^n
        
        for (int i = 0; i < numElements; i++) {
            result.push_back(i ^ (i >> 1));
        }
        
        return result;
    }
};