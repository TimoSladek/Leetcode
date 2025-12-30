class Solution {
public:
    int rob(vector<int>& nums) {
		int n = nums.size();
        if (n == 1) return nums[0];
        int prev2 = 0, prev = nums[0];
        for (int i = 2; i <= n; ++i) {
            int take = prev2 + nums[i-1];
            int noTake = prev;
            int curr = max(take, noTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};