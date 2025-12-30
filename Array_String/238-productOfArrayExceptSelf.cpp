class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefProductLeft(n), prefProductRight(n);
        vector<int> result(n);
        prefProductLeft[0] = nums[0];
        prefProductRight[0] = nums[n-1];
        for (int i = 1; i < nums.size(); ++i) {
            prefProductLeft[i] = prefProductLeft[i-1] * nums[i];
            prefProductRight[i] = prefProductRight[i-1] * nums[n-i-1];
        }
        result[0] = prefProductRight[n-2];
        result[n-1] = prefProductLeft[n-2];
        for (int i = 1; i < n-1; ++i) {
            result[i] = prefProductLeft[i-1] * prefProductRight[n-i-2];
        }
        return result;
    }
};