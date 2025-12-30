class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> jumps(n, -1);
        jumps[0] = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j <= i+nums[i]; ++j) {
                if(j > n-1)break;
                if (jumps[j] == -1) {
                    jumps[j] = jumps[i] + 1;
                } else {
                    jumps[j] = min(jumps[j], jumps[i] + i);
                }
            }
        }
        return jumps[n-1];
    }
};