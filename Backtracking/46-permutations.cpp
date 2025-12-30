class Solution {
public:
    void f(vector<int> &permut, vector<vector<int>> &result, vector<bool> &freq, vector<int>& nums) {
        if (permut.size() == nums.size()) {
            result.push_back(permut);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (freq[i]) continue;
            permut.push_back(nums[i]);
            freq[i] = true;
            f(permut, result, freq, nums);
            permut.pop_back();
            freq[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> permut;
        vector<bool> freq(nums.size(), false);
        f(permut, result, freq, nums);
        return result;
    }
};