class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 1, num = nums[0];
        for (int i = 1;i < nums.size();++i) {
            if (nums[i] == num) counter++;
            else counter--;
            if (counter == 0) {
                num = nums[i];
                counter++;
            }
        }
        return num;
    }
};