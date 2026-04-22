class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& current, int index) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        if (index == candidates.size() || target < 0) {
            return;
        }

        current.push_back(candidates[index]);
        backtrack(candidates, target - candidates[index], result, current, index);
        
        current.pop_back();

        backtrack(candidates, target, result, current, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, result, current, 0);
        return result;
    }
};