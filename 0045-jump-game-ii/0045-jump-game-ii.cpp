class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int current_end = 0;
        int farthest = 0;

        // We don't need to jump from the last element
        for (int i = 0; i < n - 1; ++i) {
            // Update the farthest point we can reach from the current index
            farthest = max(farthest, i + nums[i]);

            // If we've reached the end of the range for the current jump
            if (i == current_end) {
                jumps++;
                current_end = farthest;

                // If the new current_end already reaches or passes the last index, break
                if (current_end >= n - 1) break;
            }
        }

        return jumps;
    }
};