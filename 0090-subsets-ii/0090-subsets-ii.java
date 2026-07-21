import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        // 1. Sort the array so duplicates are adjacent
        Arrays.sort(nums);
        // 2. Start the backtracking process
        backtrack(result, new ArrayList<>(), nums, 0);
        return result;
    }

    private void backtrack(List<List<Integer>> result, List<Integer> currentSubset, int[] nums, int start) {
        // Add a copy of the current subset to the result
        result.add(new ArrayList<>(currentSubset));

        for (int i = start; i < nums.length; i++) {
            // Skip duplicates: if the current element is equal to the previous element
            // AND it's not the first choice at this recursive depth level
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            // Choose
            currentSubset.add(nums[i]);
            // Explore
            backtrack(result, currentSubset, nums, i + 1);
            // Un-choose (Backtrack)
            currentSubset.remove(currentSubset.size() - 1);
        }
    }
}