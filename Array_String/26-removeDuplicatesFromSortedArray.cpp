class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for (int i = 1;i < nums.size();++i) {
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
        }
        return k;
    }
};