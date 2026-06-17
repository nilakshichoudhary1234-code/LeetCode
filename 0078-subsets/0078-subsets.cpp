#include <vector>

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        backtrack(nums, 0, currentSubset, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int index, vector<int>& currentSubset, vector<vector<int>>& result) {
        // Base case: if we've considered all elements, add the current subset to the result
        if (index == nums.size()) {
            result.push_back(currentSubset);
            return;
        }

        // Decision 1: Include nums[index]
        currentSubset.push_back(nums[index]);
        backtrack(nums, index + 1, currentSubset, result);

        // Decision 2: Exclude nums[index] (Backtrack)
        currentSubset.pop_back();
        backtrack(nums, index + 1, currentSubset, result);
    }
};