class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, n = nums.size();
        int l = -1, sum = 0;
        for (int i = 0;i < n; ++i) {
            sum += nums[i];
            if (sum >= target) {
                while (sum >= target) {
                    ans = min(ans, i-l);
                    l++;
                    sum -= nums[l];
                }
            }
        }
        if (ans == INT_MAX) return 0;
        return ans;
    }
};