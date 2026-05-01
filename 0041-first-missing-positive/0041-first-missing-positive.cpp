class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // While the current number is in the valid range [1, n]
            // and it is not already at its correct index (nums[i]-1)
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // After placing numbers, the first index 'i' where nums[i] != i + 1
        // indicates that 'i + 1' is the missing positive integer.
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // If all numbers from 1 to n are present
        return n + 1;
    }
};