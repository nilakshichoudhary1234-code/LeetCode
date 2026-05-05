class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        // Base case: if the start index reaches the end, we've formed a permutation
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            // Swap the current element with the element at the 'start' index
            swap(nums[start], nums[i]);
            
            // Recurse to move to the next position
            backtrack(nums, start + 1, result);
            
            // Backtrack: swap back to restore the original state for the next iteration
            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
};