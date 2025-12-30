class Solution {
public:
    int search(int low, int high, vector<int>& nums, int target) {
        int mby = high+1;
        while (low <= high) {
            int mid = (high + low)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) {
                mby = mid;
                high = mid-1;
            } else {
                low = mid + 1;
            }
        }
        return mby;
    }
    int searchInsert(vector<int>& nums, int target) {
        return search(0, nums.size()-1, nums, target);
    }
};