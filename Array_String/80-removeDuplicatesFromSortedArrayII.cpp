class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int k = 2;
        for (int i = 2;i < nums.size();++i) {
            if (nums[i-1] == nums[i-2]) {
                if (nums[i] > nums[i-1]) {
                    k++;
                    continue;
                }
                int j = 1;
                while(i+j < nums.size()) {
                    if (nums[i+j] > nums[i-1]) {
                        swap(nums[i], nums[i+j]);
                        k++;
                        break;
                    }
                    j++;
                    if (i+j == nums.size()) return k;
                }
            } else {
                if (nums[i] >= nums[i-1]) {
                    k++;
                    continue;
                }
                int j = 1;
                while(i+j < nums.size()) {
                    if (nums[i+j] >= nums[i-1]) {
                        swap(nums[i], nums[i+j]);
                        k++;
                        break;
                    }
                    j++;
                    if (i+j == nums.size()) return k;
                }
            }
        }
        return k;
    }
};
