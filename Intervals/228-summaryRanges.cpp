class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return {};
        int n = nums.size(), a = nums[0], b = nums[0];
        vector<string> res;
        for (int i = 0;i < n-1; ++i) {
            if (nums[i]+1 == nums[i+1]) {
                b = nums[i+1];
                continue;
            }
            string range;
            if (a == b) {
                range = to_string(a);
            } else {
                range = to_string(a) + "->" + to_string(b);
            }
            res.push_back(range);
            a = nums[i+1];
            b = nums[i+1];
        }
        string range;
        if (a == b) {
            range = to_string(a);
        } else {
            range = to_string(a) + "->" + to_string(b);
        }
        res.push_back(range);
        return res;
    }
};