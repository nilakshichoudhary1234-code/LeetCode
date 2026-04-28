class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, vector<bool>& used) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // Skip if element is already used
            if (used[i]) continue;

            // Skip duplicates: 
            // If nums[i] == nums[i-1] and nums[i-1] was not used in the previous step,
            // it means we are at the same level of recursion and already processed this value.
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            current.push_back(nums[i]);
            
            backtrack(nums, result, current, used);
            
            // Backtrack
            used[i] = false;
            current.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        
        sort(nums.begin(), nums.end()); // Essential for duplicate handling
        backtrack(nums, result, current, used);
        
        return result;
    }
};