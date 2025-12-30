class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int res = nums[0], idx = 0, n = nums.size(), firstIdx = 0;
        for (int i = 0; i < n; ++i) {
            swap(res, nums[(idx+k)%n]);
            idx = (idx+k)%n;
            if (i != 0 && firstIdx == idx) {
                idx++;
                res = nums[idx];
                firstIdx++;
            }
        }
    }
};