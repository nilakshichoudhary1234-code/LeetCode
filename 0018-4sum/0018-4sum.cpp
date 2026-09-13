class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < n; i++) {
            // Skip duplicate for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                // Skip duplicate for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    // Use long long to prevent overflow
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicates for the third and fourth numbers
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};
