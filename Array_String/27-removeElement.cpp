class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size()-k; ++i) {
            if (nums[i] != val)continue;
            k++;
            while(i < nums.size()-k) {
                if (nums[nums.size()-k] != val) {
                    swap(nums[i], nums[nums.size()-k]);
                    break;
                }
                k++;
            }
        }
        return nums.size()-k;
    }
};