class Solution {
public:
    void f(int idx, int target, vector<int> candidates, vector<int> &comb, vector<vector<int>> &result) {
        if (idx == candidates.size()) {
            if (target == 0) {
                result.push_back(comb);
            }
            return;
        }
        if (candidates[idx] <= target) {
            comb.push_back(candidates[idx]);
            f(idx, target - candidates[idx], candidates, comb, result);
            comb.pop_back();
        }
        f(idx+1, target, candidates, comb, result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> comb;
        f(0, target, candidates, comb, result);
        return result;
    }
};