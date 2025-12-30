class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n) {
            if (i != 0 && nums[i] == nums[i-1]) {
                i++;
                continue;
            }
            int l = i+1, r = n-1;
            while (l < r) {
                int num = nums[i] + nums[l] + nums[r];
                if (num == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (nums[l] == nums[l-1] && l < r) l++;
                    while (nums[r] == nums[r+1] && l < r) r--;
                } else if (num < 0) {
                    l++;
                    while (nums[l] == nums[l-1] && l < r) l++;
                }
                else  {
                    r--;
                    while (nums[r] == nums[r+1] && l < r) r--;
                }
            }
            i++;
        }
        return ans;
    }
};