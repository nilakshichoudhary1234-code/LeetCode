class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Pruning: if the current number is greater than the target, 
            // no point in looking at this or any further (larger) numbers.
            if (candidates[i] > target) break;

            // Skip duplicates: if the current number is the same as the previous 
            // one in this loop, skip it to avoid duplicate combinations.
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            current.push_back(candidates[i]);
            
            // Move to the next index (i + 1) because each number can only be used once.
            backtrack(candidates, target - candidates[i], i + 1, current, result);
            
            // Backtrack: remove the last element to try the next candidate.
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};